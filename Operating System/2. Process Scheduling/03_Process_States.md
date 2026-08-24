# 3. Process States & 7-State Lifecycle Model

## Process Lifecycle States

As a process executes, it transitions through distinct operational states:

```
                      +-------------------+
                      |        NEW        | (Process being created)
                      +-------------------+
                                |
                        Admitted by LTS
                                |
                                v
      Suspend-Ready   +-------------------+  Dispatch (STS)   +-------------------+
  +<----------------- |       READY       | ----------------> |      RUNNING      |
  |   (Swap out)      | (In RAM, waiting) | <---------------- | (Executing on CPU)|
  |                   +-------------------+  Timer Expiry/    +-------------------+
  | Resume (Swap in)            ^            Preemption                 |
  +------------------+          |                                       |
                     |          | I/O Complete                          | I/O or Event
                     |          |                                       | Wait
                     |          |                                       v
                     |  +-------------------+                 +-------------------+
                     |  |  SUSPEND-BLOCKED  | <-------------- |  WAITING/BLOCKED  |
                     |  +-------------------+   Swap out      |  (Waiting on I/O) |
                     |          |                             +-------------------+
                     |   I/O    |
                     | Completed|
                     v          v
                 +-------------------+
                 |   SUSPEND-READY   |
                 +-------------------+
```

---

## Explanation of 7 States

| State | Location | Description |
| :--- | :--- | :--- |
| **New** | Secondary Storage | Process is being created, PCB allocated, but not yet loaded into RAM. |
| **Ready** | Main Memory (RAM) | Process is fully loaded in RAM and waiting to be assigned a CPU core. |
| **Running** | CPU | Process instructions are actively being executed by the CPU. |
| **Waiting / Blocked** | Main Memory (RAM) | Process cannot execute until an I/O event or signal completes. |
| **Terminated / Exit** | Main Memory | Process finished execution; OS deallocates resources. |
| **Suspend Ready** | Secondary Storage | Ready process was swapped out of RAM to disk to free memory space. |
| **Suspend Blocked** | Secondary Storage | Blocked process was swapped out of RAM to disk. |

---

## State Transition Causes
- **New $\to$ Ready:** Long-Term Scheduler admits process into main memory.
- **Ready $\to$ Running:** Short-Term Scheduler dispatches process to CPU.
- **Running $\to$ Ready:** Time-quantum expires or higher priority process preempts it.
- **Running $\to$ Waiting:** Process initiates an I/O request (e.g., file read) or system call.
- **Waiting $\to$ Ready:** Requested I/O operation finishes.
- **Running $\to$ Terminated:** Execution completes or fatal runtime error occurs.
