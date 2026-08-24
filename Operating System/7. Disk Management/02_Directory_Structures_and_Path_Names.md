# 2. Directory Structures & Path Names

## What is a Directory?
A **Directory** is a special container/file in the filesystem that maintains a symbol table mapping **Human-readable File Names $\to$ File Control Blocks / Inode Numbers**.

---

## Directory Structures Compared

### 1. Single-Level Directory
- All files contained in the **same single directory**.
- **Flaws:** Name collisions (two users cannot name their file `test.txt`); impossible to organize.

### 2. Two-Level Directory
- Each user has their own **User File Directory (UFD)** underneath a single Master File Directory (MFD).
- Eliminates name collisions between users, but lacks sub-grouping for a single user.

### 3. Tree-Structured Directory (Modern Standard)
- Arbitrary depth directory tree with a single **Root Directory (`/`)**.
- Users can create subdirectories at will.
- Completely solves organization and isolation.

### 4. Acyclic-Graph Directory
- Allows directories to have **shared subdirectories and files** (e.g., Hard Links and Symbolic/Soft Links).
- No cycles permitted.

### 5. General Graph Directory
- Allows arbitrary cycles; requires garbage collection reference counting to prevent memory leaks when deleting directories.

---

## Path Names
- **Absolute Path Name:** Begins at the root directory (`/`) and specifies the full path (e.g., `/home/user/documents/resume.pdf` or `C:\Users\Admin\file.txt`).
- **Relative Path Name:** Begins from the **Current Working Directory (CWD)** (e.g., `../documents/resume.pdf`).
