# 2. Process Synchronization & Race Condition

## What is Process Synchronization?
**Process Synchronization** is the coordination of execution of multiple concurrent processes that share memory or resources, ensuring orderly access and maintaining **data consistency**.

---

## What is a Race Condition?
A **Race Condition** is an undesirable situation that occurs when two or more concurrent threads or processes read and write shared data at the same time, and the **final outcome depends on the non-deterministic order of execution**.

---

## Classic Producer-Consumer Race Condition Example

Suppose `count = 5` initially:

```cpp
// Producer: count++           // Consumer: count--
register1 = count;             register2 = count;
register1 = register1 + 1;     register2 = register2 - 1;
count = register1;             count = register2;
```

### Problematic Interleaving:
1. **Producer:** `register1 = count` (reg1 = 5)
2. **Producer:** `register1 = register1 + 1` (reg1 = 6)
3. *[Context Switch to Consumer]*
4. **Consumer:** `register2 = count` (reg2 = 5)
5. **Consumer:** `register2 = register2 - 1` (reg2 = 4)
6. **Consumer:** `count = register2` (**count is now 4**)
7. *[Context Switch to Producer]*
8. **Producer:** `count = register1` (**count is now 6** - ERROR! Should be 5)

---

## How to Prevent Race Conditions
To prevent race conditions, concurrent processes must be synchronized using **Critical Section protocols** (Mutexes, Semaphores, Monitors).
