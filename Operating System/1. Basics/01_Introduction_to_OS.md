# 1. Introduction to Operating Systems

## What is an Operating System?
An **Operating System (OS)** is system software that acts as an **intermediary/bridge** between computer hardware and the user/applications.

```
+-----------------------------------+
|       User Applications           | (Browser, VS Code, Games)
+-----------------------------------+
|        Operating System           | (Windows, Linux, macOS)
+-----------------------------------+
|       Computer Hardware           | (CPU, RAM, Hard Disk, GPU)
+-----------------------------------+
```

---

## Two Primary Goals of an OS
1. **Convenience / User-friendliness:** Make the computer system easy and convenient for users to interact with.
2. **Efficiency:** Manage hardware resources (CPU, Memory, I/O devices) efficiently among competing processes.

---

## Core Functions of an OS

| Function | What the OS Does |
| :--- | :--- |
| **Process Management** | Creates, schedules, pauses, and terminates processes; allocates CPU time. |
| **Memory Management** | Allocates and deallocates RAM; tracks which memory parts are in use. |
| **File System Management** | Organizes files into directories; controls read/write permissions. |
| **Device / I/O Management** | Coordinates communication between devices (keyboard, disk, screen) via device drivers. |
| **Security & Protection** | Prevents unauthorized access to data and system resources. |
| **Error Detection** | Monitors hardware failures, division-by-zero, and memory violations. |

---

## Dual Mode Operation (User Mode vs. Kernel Mode)

To protect the system from buggy or malicious programs, modern CPUs have at least **two separate execution modes**:

```
                  +--------------------------------+
                  |           User Mode            | (Mode Bit = 1)
                  | - Executes user applications   |
                  | - Cannot access hardware directly
                  +--------------------------------+
                                  |
                           System Call (Trap)
                                  |
                                  v
                  +--------------------------------+
                  |          Kernel Mode           | (Mode Bit = 0)
                  | - Full access to all hardware  |
                  | - Privileged instructions allowed
                  +--------------------------------+
```

- **Mode Bit:** Hardware register bit (e.g., `0` for Kernel mode, `1` for User mode).
- **Transition from User to Kernel Mode:** Triggered via a **System Call**, **Hardware Interrupt**, or **Software Trap / Exception**.
