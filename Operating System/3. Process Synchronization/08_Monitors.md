# 8. Monitors in Operating Systems

## What is a Monitor?
A **Monitor** is a high-level programming language synchronization construct (encapsulated class/module) that allows threads to have both mutual exclusion and the ability to wait for a condition to become true.

- In a Monitor, **only one thread can be active inside the monitor at any given time**.
- Mutual exclusion is **handled automatically by the compiler/runtime**, preventing programming mistakes common with semaphores.

---

## Structure of a Monitor

```
+-------------------------------------------------------+
|                    MONITOR                            |
|                                                       |
|  Shared Variables / Data                              |
|                                                       |
|  Condition Variables: (e.g., condition x, y)          |
|  - x.wait(): Suspend calling thread on queue x        |
|  - x.signal(): Resume one thread waiting on queue x   |
|                                                       |
|  Entry Procedures / Methods (Mutually Exclusive):     |
|  - procedure P1(...) { ... }                          |
|  - procedure P2(...) { ... }                          |
+-------------------------------------------------------+
                           ^
                           | Entry Queue (Waiting to enter monitor)
```

---

## Condition Variables & Signaling Semantics

Condition variables in Monitors support two atomic operations:
1. **`x.wait()`:** The calling thread yields the monitor and enters the waiting queue for condition `x`.
2. **`x.signal()`:** Resumes one thread suspended on `x.wait()`.

### Two Signaling Semantics:
1. **Hoare Semantics (Signal-and-Wait):** The signaling thread immediately gives up control of the monitor to the awakened thread.
2. **Mesa Semantics (Signal-and-Continue):** The signaling thread continues executing; the awakened thread must re-check the condition in a `while` loop (Standard in Java `synchronized` & C++ `std::condition_variable`).
