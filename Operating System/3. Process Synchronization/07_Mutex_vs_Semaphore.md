# 7. Mutex vs. Semaphore (High-Frequency Interview Question)

## Core Concept
- **Mutex (Mutual Exclusion Object):** A **locking mechanism** used to synchronize access to a resource. It has an **owner**.
- **Semaphore:** A **signaling mechanism** (`"Hey, a spot is free!"`). It does **not** have an owner.

---

## Detailed Comparison

| Feature | Mutex (Mutual Exclusion) | Semaphore (Binary / Counting) |
| :--- | :--- | :--- |
| **Mechanism** | Locking mechanism | Signaling mechanism |
| **Ownership** | **Strict Ownership:** Only the thread that acquired/locked the Mutex can unlock it. | **No Ownership:** Any thread or process can call `signal()` to unblock a waiting thread. |
| **Categorization** | Object / Lock structure | Integer variable with waiting queue |
| **Values** | Binary (Locked / Unlocked) | Binary (0, 1) or Counting (0 to N) |
| **Use Case** | Protecting critical section code | Producer-consumer signaling, resource counting |
| **Behavior on Exceed** | Threads wait until lock is freed | Tracks how many resources are available |

---

## Code Example: Why Ownership Matters

```cpp
// MUTEX (Correct usage):
pthread_mutex_lock(&myMutex);
// ... Critical section ...
pthread_mutex_unlock(&myMutex); // MUST be called by the same thread!

// SEMAPHORE (Can be used across threads for signaling):
// Thread 1 (Producer):
sem_post(&dataReady); // Signals Thread 2 that data is produced

// Thread 2 (Consumer):
sem_wait(&dataReady); // Waits for signal from Thread 1
```
