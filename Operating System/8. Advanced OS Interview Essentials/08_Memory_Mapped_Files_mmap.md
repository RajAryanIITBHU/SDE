# 8. Memory-Mapped Files (`mmap`) in Operating Systems

## What is `mmap()`?
`mmap()` is a system call that maps the contents of a file on disk directly into a process's **virtual address space**.

---

## Traditional File I/O vs. Memory-Mapped I/O

```
 TRADITIONAL READ/WRITE I/O                   MEMORY-MAPPED I/O (mmap)
+-------------------------------+          +-------------------------------+
| User Buffer (User Space RAM)  |          | Process Virtual Address Space |
+-------------------------------+          | (Mapped directly to File)     |
               ^                           +-------------------------------+
       Copy data across boundary                           |
               v                                           | Direct memory pointer
+-------------------------------+                          v access (Paging)
| Kernel Buffer (Page Cache)    |          +-------------------------------+
+-------------------------------+          |  Page Cache in Kernel RAM     |
               ^                           +-------------------------------+
       Disk I/O transfer                                   ^
               v                                   Disk I/O| transfer (on fault)
+-------------------------------+          +-------------------------------+
|       Physical Disk File      |          |       Physical Disk File      |
+-------------------------------+          +-------------------------------+
```

---

## Why `mmap()` is Significantly Faster (Zero-Copy Architecture)
1. **No Double Copying:** In traditional `read()`, data is copied from disk $\to$ Kernel page cache $\to$ User buffer. In `mmap()`, the user process accesses the kernel page cache directly, **eliminating user-space copy overhead**.
2. **Lazy Demand Paging:** The OS only loads file pages into RAM when your code actually dereferences that memory location.
3. **High-Speed IPC:** Multiple processes can `mmap()` the exact same file to create a high-performance **Shared Memory IPC** channel.

---

## C Code Example using `mmap()`

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd = open("large_file.txt", O_RDONLY);
    struct stat sb;
    fstat(fd, &sb);

    // Map entire file into process memory space as a char array
    char *file_memory = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

    // Access file data just like a normal C string in RAM!
    printf("First 50 characters: %.*s\n", 50, file_memory);

    // Clean up
    munmap(file_memory, sb.st_size);
    close(fd);
    return 0;
}
```
