# 6. Deadlock Detection and Recovery

## 1. Deadlock Detection

### For Single-Instance Resources: Wait-For Graph (WFG)
- The Resource Allocation Graph is compressed into a **Wait-For Graph** by removing all resource nodes.
- Directed edge $P_i \to P_j$ exists if $P_i$ is waiting for a resource held by $P_j$.
- **Detection:** Run a standard cycle detection algorithm ($O(V + E)$ / $O(n^2)$). **Cycle $\iff$ Deadlock.**

### For Multi-Instance Resources
- Uses an algorithm similar to Banker's Safety algorithm with current `Request` matrix replacing `Need` matrix ($O(m \times n^2)$).

---

## 2. Deadlock Recovery Strategies

Once a deadlock is detected, it must be resolved using one of two methods:

### Strategy A: Process Termination
1. **Abort all deadlocked processes:** Breaks deadlock immediately, but discards all partial computations (expensive).
2. **Abort one process at a time:** Terminate one process, rerun detection, repeat until cycle is broken.
   - *Selection Criteria for Victim Process:* Lowest priority, least CPU time used, fewest resources held, batch vs interactive.

### Strategy B: Resource Preemption
1. **Selecting a Victim:** Decide which resource from which process should be preempted based on cost factors.
2. **Rollback:** Roll the victim process back to a previous safe **checkpoint** state and restart it from there.
3. **Preventing Starvation:** If the same process is repeatedly chosen as victim, it will starve.
   - *Solution:* Include a rollback counter in the cost function so a process is never picked excessively.
