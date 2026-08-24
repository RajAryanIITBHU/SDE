# 1. File Systems & Unix File System (Inode Structure)

## What is a File System?
A **File System** is the method and data structure that an operating system uses to control how data is stored, organized, named, accessed, and retrieved from persistent storage devices.

---

## File Attributes & File Control Block (FCB)
Every file on disk has metadata stored in a **File Control Block (FCB)**:
- File Name, Identifier, File Type
- Location on disk (Pointers to data blocks)
- File Size
- Access Permissions (Read, Write, Execute: `rwx`)
- Timestamps (Created, Last Modified, Last Accessed)

---

## The Unix Inode (Index Node) Architecture

In Unix/Linux filesystems (ext2, ext3, ext4), every file is represented by an **Inode** structure on disk:

```
+-------------------------------------------------------+
|                       INODE                           |
|  - File Mode / Permissions (rwxr-xr-x)                |
|  - Owner ID (UID) & Group ID (GID)                    |
|  - File Size (Bytes)                                  |
|  - Timestamps (atime, mtime, ctime)                   |
|  - Link Count (Hard link count)                       |
+-------------------------------------------------------+
| Direct Block Pointers (e.g., 12 Pointers):            |
|   -> Block 101, Block 102, ... Block 112              |
+-------------------------------------------------------+
| Single Indirect Pointer:                              |
|   -> Points to a block containing direct pointers     |
+-------------------------------------------------------+
| Double Indirect Pointer:                              |
|   -> Points to a block of single indirect blocks      |
+-------------------------------------------------------+
| Triple Indirect Pointer:                              |
|   -> Points to a block of double indirect blocks      |
+-------------------------------------------------------+
```

### Why Multi-Level Inodes are Powerful:
- **Small files (under 48 KB):** Directly accessible via the 12 direct pointers in just **1 disk read**.
- **Massive files (Terabytes):** Scalable up to maximum filesystem limits using indirect pointer hierarchies.
