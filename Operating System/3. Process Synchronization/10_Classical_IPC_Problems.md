# 10. Classical IPC Problems

Here are the 4 canonical Process Synchronization / IPC problems with standard semaphore solutions:

---

## 1. Producer-Consumer (Bounded Buffer) Problem
- **Setup:** A buffer of fixed capacity $N$. Producer puts items into the buffer; Consumer takes items out.
- **Semaphores Used:**
  - `mutex = 1` (Protects buffer critical section)
  - `empty = N` (Counts empty buffer slots)
  - `full = 0` (Counts filled buffer slots)

```cpp
// Producer:
do {
    item = produce();
    wait(empty);
    wait(mutex);
    buffer.insert(item);
    signal(mutex);
    signal(full);
} while (true);

// Consumer:
do {
    wait(full);
    wait(mutex);
    item = buffer.remove();
    signal(mutex);
    signal(empty);
    consume(item);
} while (true);
```

---

## 2. Readers-Writers Problem
- **Setup:** Multiple readers can read simultaneously. Only one writer can write at a time (exclusive access).
- **Semaphores Used:**
  - `rw_mutex = 1` (Mutual exclusion for writers)
  - `mutex = 1` (Protects `read_count` variable)
  - `int read_count = 0`

```cpp
// Reader:
wait(mutex);
read_count++;
if (read_count == 1) wait(rw_mutex); // First reader locks out writers
signal(mutex);

// ... Reading occurs ...

wait(mutex);
read_count--;
if (read_count == 0) signal(rw_mutex); // Last reader releases writer lock
signal(mutex);

// Writer:
wait(rw_mutex);
// ... Writing occurs ...
signal(rw_mutex);
```

---

## 3. Dining Philosophers Problem
- **Setup:** 5 philosophers sitting around a circular table with 5 chopsticks. A philosopher needs both left and right chopsticks to eat.
- **Problem:** If all pick up their left chopstick simultaneously $\to$ **Deadlock!**
- **Deadlock-Free Solutions:**
  1. Allow at most 4 philosophers to sit at the table simultaneously.
  2. Asymmetric solution: Odd philosophers pick left first, even philosophers pick right first.
  3. Pick both chopsticks only if both are currently available (Atomic state check).

---

## 4. Sleeping Barber Problem
- **Setup:** 1 barber chair, $N$ waiting chairs.
- If no customers, the barber sleeps. When a customer arrives:
  - If chairs are available, sits and wakes up the barber.
  - If all chairs are occupied, customer leaves.
