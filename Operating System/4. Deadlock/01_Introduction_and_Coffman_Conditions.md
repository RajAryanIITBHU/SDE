# 1. Introduction to Deadlock & Coffman Conditions

## What is a Deadlock?
A **Deadlock** is a situation in an Operating System where a set of processes are permanently blocked because **each process holds a resource that another process needs**, and none can proceed without acquiring its requested resource.

```
+------------+       Holds R1       +------------+
| Process P1 | -------------------> | Resource R1|
+------------+                      +------------+
      ^                                   |
      | Requests                     Requests
      |                                   v
+------------+       Holds R2       +------------+
| Resource R2| <------------------- | Process P2 |
+------------+                      +------------+
```

---

## 4 Necessary & Sufficient Conditions (Coffman Conditions)

A deadlock can occur **if and only if ALL FOUR** of the following conditions hold simultaneously:

```
+---------------------------------------------------------------+
| 1. Mutual Exclusion  | At least 1 non-shareable resource      |
+---------------------------------------------------------------+
| 2. Hold and Wait     | A process holds resources while        |
|                      | waiting for additional ones            |
+---------------------------------------------------------------+
| 3. No Preemption     | Resources cannot be forcibly taken     |
+---------------------------------------------------------------+
| 4. Circular Wait     | A closed chain P0 -> P1 -> ... -> P0   |
|                      | of cyclic resource dependencies exists |
+---------------------------------------------------------------+
```

### 1. Mutual Exclusion
- Resources must be non-shareable (e.g., Printer, Mutex lock). Only one process can use a resource instance at a time.

### 2. Hold and Wait
- A process is currently holding at least one resource and is waiting to acquire additional resources held by other processes.

### 3. No Preemption
- Resources cannot be forcibly seized from a process; they can only be released voluntarily by the process holding them after finishing its task.

### 4. Circular Wait
- A closed loop chain of processes $\{P_0, P_1, \dots, P_n\}$ exists such that $P_0$ is waiting for a resource held by $P_1$, $P_1$ is waiting for $P_2$, $\dots$, and $P_n$ is waiting for $P_0$.
