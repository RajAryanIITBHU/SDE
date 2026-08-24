# 8. Starvation and Aging in Operating Systems

## What is Starvation?
**Starvation** (also called **Indefinite Blocking**) is a situation where a runnable process waits indefinitely in the Ready Queue because other processes with higher priority or shorter burst times continually preempt it.

---

## Causes of Starvation
1. **Priority Scheduling without Aging:** High-priority jobs keep arriving continuously.
2. **SJF / SRTF Scheduling:** A stream of very short burst time jobs prevents longer jobs from ever running.
3. **Unfair Resource Allocation:** Non-FIFO queue discipline for shared resources.

---

## Starvation vs. Deadlock

| Feature | Starvation | Deadlock |
| :--- | :--- | :--- |
| **Definition** | A process waits indefinitely due to unfair prioritization | Two or more processes are permanently stuck waiting for resources held by each other |
| **Process State** | Process is in **Ready** state (runnable, but not picked) | Processes are in **Waiting / Blocked** state |
| **Possibility of Termination** | Might eventually run if higher priority stream stops | Can **never** resolve without external intervention |
| **Resource Involvement** | One or more resources | Cyclic dependencies of at least 2 resources |

---

## What is Aging?
**Aging** is the primary technique used by operating systems to prevent starvation.

### How Aging Works
- The OS periodically increments the priority of processes waiting in the Ready queue for a specified duration (e.g., increase priority by 1 every 15 minutes of wait time).
- Eventually, even the lowest-priority process will reach the highest priority level in the system and execute.

```
Initial Priority: 100 (Lowest)
After 15 min wait -> Priority 99
After 30 min wait -> Priority 98
...
After 1500 min wait -> Priority 0 (Highest) -> Dispatched to CPU!
```
