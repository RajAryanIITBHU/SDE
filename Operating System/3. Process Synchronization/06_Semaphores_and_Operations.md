# 6. Semaphores and Atomic Operations

## What is a Semaphore?
A **Semaphore** is an integer variable $S$ accessed exclusively through two standard atomic operations: **`wait()`** (also called `P` or down) and **`signal()`** (also called `V` or up).

Introduced by Edsger Dijkstra in 1965.

---

## The Two Atomic Operations

### 1. `wait(S)` / `P(S)`
Decrements the semaphore value. If the value becomes negative, the calling process blocks.

```cpp
void wait(Semaphore S) {
    S.value--;
    if (S.value < 0) {
        add this process to S.queue;
        block(); // Sleep / suspend process
    }
}
```

### 2. `signal(S)` / `V(S)`
Increments the semaphore value. If any processes are waiting, wakes up one of them.

```cpp
void signal(Semaphore S) {
    S.value++;
    if (S.value <= 0) {
        remove a process P from S.queue;
        wakeup(P); // Place in Ready queue
    }
}
```

---

## Types of Semaphores

```
                       +-------------------+
                       |    SEMAPHORES     |
                       +-------------------+
                                 |
                 +---------------+---------------+
                 |                               |
                 v                               v
        +-------------------+           +-------------------+
        | Counting Semaphore|           | Binary Semaphore  |
        | Range: [0, N]     |           | Range: [0, 1]     |
        | Resource counting |           | Mutual Exclusion  |
        +-------------------+           +-------------------+
```

### 1. Counting Semaphore
- **Value Range:** Unrestricted integer range ($[0, N]$).
- **Purpose:** Used to manage access to a finite pool of $N$ identical resource instances (e.g., database connection pool, printer pool).

### 2. Binary Semaphore
- **Value Range:** Only `0` or `1`.
- **Purpose:** Used for Mutual Exclusion (acts like a basic lock).
