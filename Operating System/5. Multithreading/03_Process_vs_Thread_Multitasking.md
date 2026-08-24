# 3. Process-Based vs. Thread-Based Multitasking

Multitasking is the ability of an OS to execute multiple concurrent operations. It is realized in two distinct ways:

---

## 1. Process-Based Multitasking (Multiprocessing)
- Multiple independent processes run concurrently (e.g., running Chrome, Spotify, and VS Code simultaneously).
- Each process has its **own completely isolated address space** in RAM.
- **Communication:** Expensive (Requires IPC mechanisms: Pipes, Sockets, Shared Memory).
- **Isolation:** High safety (a crash in one process does not affect others).

---

## 2. Thread-Based Multitasking (Multithreading)
- Multiple threads within the **same process** execute concurrently (e.g., in a word processor, one thread renders the UI, another auto-saves, and a third checks spellings).
- All threads **share the same address space** (Heap, Globals, Code).
- **Communication:** Inexpensive and fast (direct read/write to shared memory).
- **Isolation:** Low safety (an unhandled segmentation fault in one thread terminates the whole process).

---

## Direct Comparison Table

| Feature | Process | Thread |
| :--- | :--- | :--- |
| **Address Space** | Separate, isolated virtual address space | Shares address space with peer threads |
| **Creation Overhead** | Heavyweight (allocating memory, page tables) | Lightweight (only stack and registers) |
| **Context Switch Overhead** | High (flushes TLB and changes page directory) | Low (no address space / TLB flush needed) |
| **Inter-communication** | Requires IPC (Pipes, Sockets, Shared Memory) | Direct memory access via shared variables |
| **Crash Impact** | Isolated to that single process | Can crash the entire parent process |
