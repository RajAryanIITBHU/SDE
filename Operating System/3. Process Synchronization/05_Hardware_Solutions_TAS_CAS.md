# 5. Hardware-Based Synchronization: Test-and-Set & Compare-and-Swap

Modern multi-core processors provide special **atomic (uninterruptible)** hardware instructions.

---

## 1. Disabling Interrupts (Single-Core Only)
- **Concept:** Process disables hardware interrupts before entering critical section and re-enables them on exit.
- **Flaws:**
  - Ineffective on multi-core / multiprocessor architectures.
  - Giving user processes permission to disable interrupts can freeze the whole OS.

---

## 2. Test-and-Set (TAS) Instruction
`TestAndSet` reads the current value of a memory location and sets it to `true` **atomically** in one clock cycle.

```cpp
// Hardware definition (Executed Atomically):
bool TestAndSet(bool *target) {
    bool rv = *target;
    *target = true;
    return rv;
}

// Critical Section Mutual Exclusion using TAS:
bool lock = false;

do {
    while (TestAndSet(&lock)); // Busy-wait (Spinlock)
    
    // CRITICAL SECTION
    
    lock = false;              // Release lock
    
    // REMAINDER SECTION
} while (true);
```

---

## 3. Compare-and-Swap (CAS) Instruction
`CompareAndSwap` compares the value of memory location `v` with `expected`. If equal, it updates `v` to `new_val`.

```cpp
// Hardware definition (Executed Atomically):
int CompareAndSwap(int *value, int expected, int new_value) {
    int temp = *value;
    if (*value == expected) {
        *value = new_value;
    }
    return temp;
}

// Critical Section using CAS:
int lock = 0;

do {
    while (CompareAndSwap(&lock, 0, 1) != 0); // Spinlock
    
    // CRITICAL SECTION
    
    lock = 0;                                 // Release lock
    
    // REMAINDER SECTION
} while (true);
```

---

## What is a Spinlock?
A synchronization lock where waiting threads loop continuously (**busy waiting**) checking if the lock is available.
- **Best Use Case:** Short critical sections on multi-core processors (avoids context-switch overhead).
- **Worst Use Case:** Single-core CPU or long critical sections (wastes CPU cycles).
