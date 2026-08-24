# 3. Kernel in Operating Systems

## What is a Kernel?
The **Kernel** is the **core, central component** of an Operating System. It loads into memory first during system boot and remains permanently resident in RAM. It has complete control over everything occurring in the system.

---

## Key Responsibilities of the Kernel
1. **CPU / Process Scheduling:** Decides which process runs on which CPU core.
2. **Memory Allocation:** Manages physical RAM and virtual address translation.
3. **Hardware Device Communication:** Talks to peripherals using device drivers.
4. **System Call Handling:** Executes privileged hardware operations requested by user applications.

---

## Kernel Architectures Compared

```
   MONOLITHIC KERNEL                      MICROKERNEL
+-----------------------+           +-----------------------+
|  User Applications    |           |  User Applications    |
+-----------------------+           +-----------------------+
|   VFS / File System   |           | File System  | Net    | (User Space)
|   Device Drivers      |           +-----------------------+
|   Memory Management   |           | Microkernel:          |
|   Process Scheduling  | (Kernel)  | IPC, Scheduling, Paging (Kernel Space)
+-----------------------+           +-----------------------+
|       Hardware        |           |       Hardware        |
+-----------------------+           +-----------------------+
```

### 1. Monolithic Kernel
- **Structure:** All OS services (File system, Network stack, Memory manager, Device drivers) run inside the same address space in **Kernel Mode**.
- **Pros:** Fast execution (communication is via direct function calls).
- **Cons:** A crash in a single device driver can crash the entire OS; large codebase.
- **Examples:** Linux, Traditional Unix.

### 2. Microkernel
- **Structure:** Only bare minimum services (IPC, basic CPU scheduling, low-level memory management) run in **Kernel Mode**. Everything else (File system, Device drivers) runs as servers in **User Mode**.
- **Pros:** Highly secure, modular, and fault-tolerant (if a driver crashes, only that server restarts).
- **Cons:** Slower performance due to frequent context switches and IPC overhead.
- **Examples:** Minix, QNX, L4.

### 3. Hybrid Kernel
- **Structure:** Combines the speed of monolithic kernels with the modular structure of microkernels.
- **Examples:** Windows NT / 10 / 11, macOS (XNU Kernel).

---

## Comparison Summary

| Feature | Monolithic Kernel | Microkernel |
| :--- | :--- | :--- |
| **Size** | Large | Very Small |
| **Execution Speed** | Fast (direct function calls) | Slower (IPC message overhead) |
| **Crash Vulnerability** | High (one bug crashes all) | Low (isolated server crashes) |
| **Extensibility** | Hard (requires re-compiling) | Easy (just start a new user daemon) |
| **Real-World Use** | Linux, Android | QNX (automotive, aerospace) |
