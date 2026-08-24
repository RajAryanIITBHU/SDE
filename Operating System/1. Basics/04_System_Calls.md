# 4. System Calls in Operating Systems

## What is a System Call?
A **System Call** is the programmatic interface provided by the OS that allows a user-space application to request a service from the kernel (such as creating a process, reading a file, or sending network packets).

---

## How a System Call Works (Step-by-Step)

```
1. User Program calls library function (e.g., printf() -> write())
2. C Library loads system call number into register (e.g., EAX = 4)
3. Executes a Software Interrupt / Trap instruction (e.g., 'syscall' / 'int 0x80')
4. Hardware switches CPU from User Mode (1) -> Kernel Mode (0)
5. Kernel inspects System Call Table to find the handler function
6. Kernel executes the requested privileged operation
7. Kernel returns result and switches CPU back to User Mode (1)
```

---

## Major Categories of System Calls

### 1. Process Control
- `fork()`: Creates a new child process (exact duplicate of parent).
- `exec()`: Replaces current process image with a new executable program.
- `wait()`: Makes parent process wait until one of its child processes terminates.
- `exit()`: Terminates the current process and frees its resources.

### 2. File Management
- `open()`: Opens or creates a file descriptor.
- `read()`: Reads data from a file descriptor into a buffer.
- `write()`: Writes data from a buffer to a file descriptor.
- `close()`: Closes an open file descriptor.

### 3. Device Management
- `ioctl()`: Controls hardware device parameters.
- `read()`, `write()`: Transfers data to/from hardware peripherals.

### 4. Information Maintenance
- `getpid()`: Returns the Process ID of the calling process.
- `time()`: Returns the current system clock time.

### 5. Communication (IPC)
- `pipe()`: Creates a unidirectional data channel for IPC.
- `shmget()`, `shmat()`: Allocates and attaches shared memory segments.
- `socket()`: Creates an endpoint for network communication.

---

## Important Interview Question: `fork()` Deep Dive

```cpp
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        // Fork failed
    } else if (pid == 0) {
        // Child process gets return value 0
        printf("Hello from Child! PID: %d\n", getpid());
    } else {
        // Parent process receives Child's PID
        printf("Hello from Parent! Child PID: %d\n", pid);
    }
    return 0;
}
```

- **Number of processes created after $n$ sequential `fork()` calls:**
  $$\text{Total Processes} = 2^n$$
  $$\text{Child Processes Created} = 2^n - 1$$
