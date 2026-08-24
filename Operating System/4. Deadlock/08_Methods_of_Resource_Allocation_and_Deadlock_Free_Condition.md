# 8. Methods of Resource Allocation & Deadlock-Free Conditions

## Resource Allocation Methods

1. **Resource Ordering (Hierarchical Allocation):** Assign integer priorities to all resources; processes must acquire locks in monotonically increasing order.
2. **All-or-Nothing Allocation:** Try to acquire all needed resources in a single atomic step using non-blocking primitives (`try_lock()`). If any resource fails, release all acquired locks and retry.

---

## Minimum Resources Required for Deadlock-Free Execution

A classic formula tested in university exams and technical rounds:

$$\text{For } n \text{ processes where each process requires at most } k \text{ instances of a single resource type:}$$

$$\text{Minimum Instances } R \text{ to GUARANTEE no deadlock} = n \cdot (k - 1) + 1$$

- **Proof / Worst-Case Analysis:**
  - In the absolute worst case, all $n$ processes acquire $(k - 1)$ resources and are stuck waiting for their final 1 resource.
  - Adding just $+1$ additional resource guarantees at least 1 process receives its $k$-th resource, finishes, releases all its $k$ instances, enabling all other processes to finish.
