# 9. Priority Inversion and Solutions

## What is Priority Inversion?
**Priority Inversion** is a scheduling anomaly where a **high-priority process is indirectly preempted/delayed by a low-priority process**.

---

## Classic Priority Inversion Scenario

Suppose we have 3 processes:
- $H$ (High Priority)
- $M$ (Medium Priority)
- $L$ (Low Priority)
- Shared Resource $R$ (protected by a mutex)

```
Timeline:
1. L runs and acquires lock on Resource R.
2. H arrives and preempts L.
3. H tries to acquire Resource R, but R is locked by L. H blocks (sleeps).
4. L resumes to finish using R.
5. M arrives (doesn't need R). Since Priority(M) > Priority(L), M preempts L!
6. M executes for a long time while L cannot finish, and H stays blocked!

RESULT: Medium process M delays High process H! (Priority is inverted)
```

*(Famous historical occurrence: NASA's Mars Pathfinder spacecraft mission in 1997).*

---

## Solutions to Priority Inversion

### 1. Priority Inheritance Protocol (PIP)
- **Rule:** When high-priority process $H$ blocks waiting for a resource held by low-priority process $L$, **$L$ temporarily inherits the high priority of $H$**.
- **Result:** Medium process $M$ cannot preempt $L$. As soon as $L$ releases the resource, its priority drops back to normal, and $H$ immediately preempts and executes.

### 2. Priority Ceiling Protocol (PCP)
- **Rule:** Each resource is assigned a priority ceiling equal to the priority of the highest-priority task that could ever lock it.
- Prevents both priority inversion and deadlocks.
