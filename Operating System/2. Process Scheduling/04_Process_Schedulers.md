# 4. Types of Process Schedulers

Operating Systems use three distinct schedulers to manage the flow of processes:

---

## 1. Long-Term Scheduler (LTS) / Job Scheduler
- **Role:** Selects processes from secondary storage (Job Pool) and loads them into RAM (Ready Queue).
- **Execution Frequency:** Very infrequent (seconds to minutes).
- **Primary Objective:** Controls the **Degree of Multiprogramming** (total number of processes in RAM).
- **Balance:** Maintains a healthy mix of **CPU-bound** and **I/O-bound** processes.

---

## 2. Short-Term Scheduler (STS) / CPU Scheduler
- **Role:** Selects which process from the Ready Queue in RAM gets CPU time next.
- **Execution Frequency:** Extremely frequent (every 10–100 milliseconds).
- **Primary Objective:** Maximizes CPU utilization and minimizes response time.

---

## 3. Medium-Term Scheduler (MTS) / Swapper
- **Role:** Handles **Swapping** processes between RAM and Swap Space on Disk.
- **Execution Frequency:** Moderate frequency.
- **Primary Objective:** Reduces the Degree of Multiprogramming when RAM is exhausted, preventing thrashing.

---

## Comparison Table

| Feature | Long-Term Scheduler (LTS) | Short-Term Scheduler (STS) | Medium-Term Scheduler (MTS) |
| :--- | :--- | :--- | :--- |
| **Alternate Name** | Job Scheduler | CPU Scheduler | Swapper |
| **Speed** | Slowest | Fastest (runs in ms) | Medium |
| **Execution Frequency** | Infrequent | Highly frequent | Moderate |
| **Key Responsibility** | Controls Degree of Multiprogramming | Allocates CPU to ready process | Swapping (in / out) to relieve RAM pressure |
| **State Transition** | New $\to$ Ready | Ready $\to$ Running | Ready $\leftrightarrow$ Suspend Ready |
| **Presence in Time-Sharing** | Often absent / minimal | Always present | Present |
