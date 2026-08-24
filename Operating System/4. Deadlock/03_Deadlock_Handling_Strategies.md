# 3. Deadlock Handling Strategies

Operating systems handle deadlocks through four main approaches:

---

## 1. Deadlock Ignorance (The Ostrich Algorithm)
- **Principle:** Pretend that deadlocks never happen. If a deadlock occurs, let the user or administrator manually kill frozen processes or reboot.
- **Why it is used:** Deadlocks are rare in standard desktop systems, and the cost/overhead of continuously checking for deadlocks is much higher than the occasional freeze.
- **Used by:** Windows, Linux, Android, iOS.

---

## 2. Deadlock Prevention
- **Principle:** Design system resource allocation protocols such that **at least one of the 4 Coffman conditions can NEVER hold**.
- **Outcome:** Guarantees no deadlock, but leads to low device utilization and poor throughput.

---

## 3. Deadlock Avoidance
- **Principle:** Dynamic runtime analysis. Whenever a process requests a resource, the OS evaluates whether granting it leaves the system in a **Safe State**.
- **Key Algorithm:** **Banker's Algorithm** (Dijkstra).
- **Safe State:** A state where there exists at least one execution sequence (Safe Sequence) $\langle P_1, P_2, \dots, P_n \rangle$ such that every process can satisfy its maximum demands and finish without deadlocking.

---

## 4. Deadlock Detection and Recovery
- **Principle:** Allow deadlocks to happen freely. Periodically run a **Deadlock Detection Algorithm** (e.g., cycle check on Wait-For Graph).
- **Recovery:** When detected, break the deadlock by:
  - **Process Termination:** Abort all deadlocked processes or abort one process at a time until the cycle is resolved.
  - **Resource Preemption:** Preempt resources from a victim process and roll it back to a safe checkpoint.

---

## Comparison Summary Table

| Strategy | Overhead | Resource Utilization | Approach |
| :--- | :--- | :--- | :--- |
| **Ignorance** | Zero | High | Ignore completely |
| **Prevention** | Low to Medium | Low (rigid constraints) | Eliminate 1 of 4 Coffman conditions |
| **Avoidance** | High (runtime checks) | Moderate to High | Grant only if state stays Safe |
| **Detection & Recovery** | High (periodic checks) | High | Detect post-facto and resolve |
