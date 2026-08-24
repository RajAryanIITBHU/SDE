# 2. Process Control Block (PCB) & Process Table

## What is a Process Control Block (PCB)?
A **Process Control Block (PCB)**, also known as a **Task Control Block**, is a kernel data structure that stores all information and context needed to manage a specific process.

---

## Fields in a Process Control Block (PCB)

```
+------------------------------------+
|            Process ID (PID)        |
+------------------------------------+
|            Process State           | (Ready, Running, Waiting...)
+------------------------------------+
|        Program Counter (PC)        | (Address of next instruction)
+------------------------------------+
|           CPU Registers            | (Accumulators, Index registers, Stack pointer)
+------------------------------------+
|       CPU Scheduling Info          | (Priority, Queue pointers)
+------------------------------------+
|      Memory Management Info        | (Page tables, Base/Limit registers)
+------------------------------------+
|          Accounting Info           | (CPU time used, Time limits)
+------------------------------------+
|           I/O Status Info          | (List of open files, Allocated devices)
+------------------------------------+
```

---

## What is the Process Table?
- The **Process Table** is an array of PCBs maintained in kernel space.
- Each entry corresponds to an active process in the system.
- It allows the OS to quickly index, search, and manage all running processes by their **PID**.

---

## Context Switching

**Context Switching** is the mechanism where the CPU stops executing one process, saves its state into its PCB, and restores the saved state of another process from its PCB.

```
Process P1                    OS / Kernel                    Process P2
    |                              |                              |
 Executing                         |                              |
    | --- Timer Interrupt -------->|                              |
    |                         Save state to                       |
    |                            PCB(P1)                          |
    |                              |                              |
  Idle                        Load state from                     |
    |                            PCB(P2)                          |
    |                              |----------------------------->|
    |                              |                          Executing
```

- **Context Switch Overhead:** The time spent saving/restoring registers is **pure overhead** because no productive user computation happens during switching.
