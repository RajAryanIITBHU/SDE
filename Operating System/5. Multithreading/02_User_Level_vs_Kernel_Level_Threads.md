# 2. User-Level Threads (ULT) vs. Kernel-Level Threads (KLT)

Threads can be implemented either purely in user-space or directly supported by the kernel:

---

## 1. User-Level Threads (ULT)
- **Managed by:** User-level thread libraries (e.g., POSIX pthreads without kernel thread mapping, Green threads).
- **Kernel Awareness:** The kernel has **zero knowledge** of user-level threads; it only sees the single parent process.
- **Context Switch:** Performed in user space—extremely fast (no kernel mode switch).
- **Major Disadvantage (Blocking I/O):** If one user thread makes a blocking system call (e.g., file read), **the entire process and all its threads block**.

---

## 2. Kernel-Level Threads (KLT)
- **Managed by:** Directly by the Operating System Kernel.
- **Kernel Awareness:** The kernel maintains a TCB for every thread and schedules them independently across CPU cores.
- **Context Switch:** Requires a mode switch to kernel space (slower than ULT).
- **Major Advantage:** If one thread blocks on I/O, the kernel can schedule another thread from the same process on another core.

---

## Comparison Table

| Feature | User-Level Threads (ULT) | Kernel-Level Threads (KLT) |
| :--- | :--- | :--- |
| **Creation & Management** | By user thread library in user space | By OS Kernel via system calls |
| **Context Switch Speed** | Fast (No mode switch) | Slower (Requires mode switch) |
| **Blocking System Call** | Entire process blocks | Only the calling thread blocks |
| **Multi-Core Parallelism** | Cannot utilize multiple CPU cores | Native true multi-core parallel execution |
| **OS Portability** | Highly portable across OS platforms | Dependent on OS kernel support |
| **Examples** | GNU Pth, Java Green Threads | Windows Threads, Linux `clone()` (NPTL) |
