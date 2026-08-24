# 5. Benefits and Pitfalls of Multithreading

## Benefits of Multithreading

1. **Responsiveness:** Allows interactive applications to continue running (e.g., UI remains responsive while a background thread downloads a large file).
2. **Resource Sharing:** Threads naturally share memory, code, and file descriptors without needing expensive IPC pipes.
3. **Economy (Cost-Effective):** Allocating memory and context-switching for threads is significantly cheaper than full processes.
4. **Scalability on Multi-Core Architectures:** Different threads can execute simultaneously on multiple physical CPU cores.

---

## Pitfalls & Challenges of Multithreading

1. **Race Conditions:** Unsynchronized access to shared data produces non-deterministic, buggy behavior.
2. **Deadlocks:** Threads holding mutexes and waiting on other mutexes in cyclic loops.
3. **Debugging Complexity:** Non-deterministic execution order makes reproducing multi-threaded bugs difficult.
4. **False Sharing:** Two threads on different CPU cores modifying independent variables that happen to reside on the **same CPU cache line** (64 bytes), causing continuous cache invalidation and severe slowdown.
5. **Thread Safety:** Ensuring libraries and functions can be safely invoked from multiple threads concurrently.
