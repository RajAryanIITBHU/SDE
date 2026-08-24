# 4. Multithreading Models

To connect User-Level Threads (ULT) with Kernel-Level Threads (KLT), operating systems use three primary multithreading mapping models:

---

## 1. Many-to-One Model ($M : 1$)
- Maps many user-level threads to a **single kernel thread**.
- **Pros:** Fast thread creation and switching handled entirely in user space.
- **Cons:** If one thread makes a blocking system call, all threads block; cannot run in parallel on multi-core CPUs.
- **Examples:** Solaris Green Threads, GNU Portable Threads.

---

## 2. One-to-One Model ($1 : 1$)
- Maps each user-level thread directly to **its own dedicated kernel thread**.
- **Pros:** Full concurrency; a blocking thread does not affect others; true multi-core parallel execution.
- **Cons:** Creating a user thread creates a kernel thread (higher memory overhead; typically limits max thread count).
- **Used by:** Windows, Linux (NPTL), macOS, modern Java VMs.

---

## 3. Many-to-Many Model ($M : N$)
- Multiplexes many user-level threads onto a smaller or equal number of kernel-level threads ($M \ge N$).
- **Pros:** Combines the best of both worlds (cheap user-level thread creation + true kernel multi-core dispatching).
- **Cons:** Complex to implement in the OS scheduler.

---

## 4. Two-Level Model
- A variation of the Many-to-Many model that allows certain critical user threads to be bound directly $1:1$ to a dedicated kernel thread.

---

## Model Comparison

| Model | Multi-Core Parallelism | Blocking I/O Behavior | Kernel Overhead |
| :--- | :---: | :--- | :--- |
| **Many-to-One ($M:1$)** | ❌ No | Entire process blocks | Minimal |
| **One-to-One ($1:1$)** | ✅ Yes | Only calling thread blocks | High (1 kernel thread per user thread) |
| **Many-to-Many ($M:N$)** | ✅ Yes | Kernel switches to other thread | Moderate |
