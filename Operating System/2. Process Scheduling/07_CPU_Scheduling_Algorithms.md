# 7. CPU Scheduling Algorithms

Here is a complete breakdown of all major CPU scheduling algorithms:

---

## 1. First-Come, First-Served (FCFS)
- **Nature:** Non-Preemptive.
- **Criteria:** Process that arrives first gets the CPU first (FIFO Queue).
- **Convoy Effect:** If a CPU-bound process with a huge burst time arrives first, all short I/O-bound processes get stuck behind it, leading to poor average waiting times and low device utilization.

---

## 2. Shortest Job First (SJF)
- **Nature:** Non-Preemptive.
- **Criteria:** Process with the smallest Burst Time (BT) is selected first.
- **Optimality:** Provably achieves the **minimum average waiting time** among all non-preemptive algorithms.
- **Drawback:** Cannot be implemented in practice without knowing future CPU burst times in advance (estimated via Exponential Moving Average $\tau_{n+1} = \alpha t_n + (1 - \alpha)\tau_n$).

---

## 3. Shortest Remaining Time First (SRTF)
- **Nature:** Preemptive version of SJF.
- **Criteria:** When a new process arrives, if its remaining burst time is smaller than the currently executing process's remaining burst time, the CPU is preempted.
- **Optimality:** Provides the lowest possible average waiting time of any scheduling algorithm.

---

## 4. Round Robin (RR)
- **Nature:** Preemptive.
- **Criteria:** Each process gets executed for a fixed **Time Quantum (TQ)** (e.g., 20 ms). When TQ expires, the process is preempted and moved to the back of the Ready FIFO queue.
- **Time Quantum Tradeoff:**
  - **Too Large:** Degenerates into FCFS.
  - **Too Small:** Excessive context-switching overhead kills CPU efficiency.
  - **Rule of Thumb:** 80% of CPU bursts should be shorter than the time quantum.

---

## 5. Priority Scheduling
- **Nature:** Can be Preemptive or Non-Preemptive.
- **Criteria:** Process with the highest priority (conventionally smallest integer = highest priority) runs first.
- **Problem: Starvation (Indefinite Blocking):** Low-priority processes may never execute if high-priority processes keep arriving.
- **Solution: Aging:** Gradually increase the priority of processes that wait in the ready queue for a long time.

---

## 6. Multi-Level Queue (MLQ) & Multi-Level Feedback Queue (MLFQ)
- **Multi-Level Queue (MLQ):** Ready queue is split into distinct queues (e.g., System processes > Interactive processes > Batch processes). Each queue has its own scheduling algorithm.
- **Multi-Level Feedback Queue (MLFQ):** Allows processes to **move between queues**:
  - New processes enter the highest priority queue with small TQ.
  - If a process uses its full time quantum (CPU-bound), it is demoted to a lower priority queue with larger TQ.
  - I/O-bound processes remain at top priority queues for fast responsiveness.
