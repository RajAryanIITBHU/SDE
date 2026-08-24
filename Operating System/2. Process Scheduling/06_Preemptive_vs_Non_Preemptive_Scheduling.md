# 6. Preemptive vs. Non-Preemptive Scheduling

## Core Concepts

### 1. Non-Preemptive Scheduling
- **Definition:** Once the CPU has been allocated to a process, the process keeps the CPU until it either **terminates** or **voluntarily yields** CPU to wait for I/O.
- **Key Advantage:** Simpler, low overhead (no unexpected context switches), no race conditions on shared kernel data structures.
- **Disadvantage:** A process with a long CPU burst or infinite loop can starve all other processes.

### 2. Preemptive Scheduling
- **Definition:** The OS can **forcibly interrupt and remove** the currently executing process from the CPU (e.g., when its time slice expires or a higher priority process arrives).
- **Key Advantage:** High responsiveness, essential for modern interactive and real-time operating systems.
- **Disadvantage:** Higher context switching overhead; requires synchronization mechanisms for shared data.

---

## CPU Scheduling Criteria & Important Formulas

| Metric | Definition | Formula |
| :--- | :--- | :--- |
| **Arrival Time (AT)** | Time at which the process arrives in the Ready queue | Given |
| **Burst Time (BT)** | Time required by the process for CPU execution | Given |
| **Completion Time (CT)** | Time at which the process completely finishes execution | From Gantt Chart |
| **Turnaround Time (TAT)** | Total time elapsed from arrival to completion | $\text{TAT} = \text{CT} - \text{AT}$ |
| **Waiting Time (WT)** | Total time spent sitting in the Ready queue waiting for CPU | $\text{WT} = \text{TAT} - \text{BT}$ |
| **Response Time (RT)** | Time from arrival until the process gets the CPU for the first time | $\text{RT} = \text{First CPU Time} - \text{AT}$ |

---

## Comparison Table

| Feature | Preemptive Scheduling | Non-Preemptive Scheduling |
| :--- | :--- | :--- |
| **Interruption** | CPU can be forcibly reclaimed | Process cannot be stopped until it yields |
| **Context Switching** | Frequent (higher overhead) | Minimal (lower overhead) |
| **Response Time** | Fast and predictable | Can be very slow |
| **Starvation Risk** | Low (with aging / round robin) | High (long jobs delay short jobs) |
| **Algorithms** | Round Robin, SRTF, Preemptive Priority | FCFS, Non-Preemptive SJF, Priority (Non-P) |
