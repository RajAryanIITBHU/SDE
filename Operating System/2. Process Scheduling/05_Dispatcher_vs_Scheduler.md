# 5. Dispatcher vs. Scheduler

## The Difference Explained Simply
- **Scheduler:** The **decision maker** (selects *which* process should run next from the Ready queue).
- **Dispatcher:** The **executioner** (gives actual CPU control to the process selected by the scheduler).

---

## What Does the Dispatcher Do?
Once the CPU scheduler picks a process, the **Dispatcher** performs the physical handover:

1. **Context Switching:** Saves registers/state of the old process and loads state of the new process.
2. **Mode Switching:** Switches CPU from **Kernel Mode (0)** to **User Mode (1)**.
3. **Jump to Instruction:** Sets the Program Counter (PC) to the appropriate location in the user program to restart execution.

---

## Dispatch Latency
**Dispatch Latency** is the time elapsed between stopping one process and starting the next process.

$$\text{Dispatch Latency} = \text{Time taken to save context of P1} + \text{Time taken to load context of P2}$$

- To maximize system efficiency, dispatch latency must be as small as possible (typically measured in microseconds).

---

## Key Differences Summary

| Property | CPU Scheduler | Dispatcher |
| :--- | :--- | :--- |
| **Role** | Algorithm that chooses the next process | Module that handles the actual CPU switch |
| **Type** | Algorithm (e.g., FCFS, Round Robin, SJF) | Hardware / Kernel code module |
| **Overhead** | Computational selection overhead | Context switch and mode switch latency |
| **Trigger** | Process terminates, blocks, or timer expires | Runs immediately after scheduler decides |
