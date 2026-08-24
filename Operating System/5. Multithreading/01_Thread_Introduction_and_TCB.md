# 1. Threads Introduction & Thread Control Block (TCB)

## What is a Thread?
A **Thread** is the smallest unit of CPU execution (often called a **Lightweight Process**). A process can contain multiple threads executing concurrently within the same address space.

---

## Single-Threaded vs. Multi-Threaded Process Structure

```
 SINGLE-THREADED PROCESS                    MULTI-THREADED PROCESS
+------------------------------------+   +------------------------------------+
|  Code   |   Data   |     Files     |   |  Code   |   Data   |     Files     |
+------------------------------------+   +------------------------------------+
| Registers | Stack                  |   | Regs | Regs | Regs | Stack|Stack|Stack
+------------------------------------+   |  T1  |  T2  |  T3  |  T1  |  T2 |  T3 |
|              HEAP                  |   +------------------------------------+
+------------------------------------+   |               HEAP                 |
                                         +------------------------------------+
```

---

## Shared vs. Private Thread Components

| Component | Shared Across All Threads in Process? | Private / Unique to Each Thread? |
| :--- | :---: | :---: |
| **Code Segment** | ✅ Shared | ❌ |
| **Data Segment (Globals/Statics)**| ✅ Shared | ❌ |
| **Heap Memory** | ✅ Shared | ❌ |
| **Open Files & Sockets** | ✅ Shared | ❌ |
| **Program Counter (PC)** | ❌ | ✅ Private (Tracks thread's current instruction) |
| **CPU Registers** | ❌ | ✅ Private (Stores thread's working context) |
| **Stack Memory** | ❌ | ✅ Private (Local variables & function calls) |

---

## Thread Control Block (TCB)
The **TCB** is a small kernel/user structure storing metadata for a single thread:
1. **Thread ID (TID)**
2. **Thread State** (Ready, Running, Blocked)
3. **Saved CPU Registers & Stack Pointer**
4. **Program Counter (PC)**
5. **Pointer to parent process's PCB**
