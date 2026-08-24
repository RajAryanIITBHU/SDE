# 1. Inter-Process Communication (IPC)

## What is IPC?
Processes executing concurrently in an OS can be:
- **Independent Processes:** Cannot affect or be affected by other processes.
- **Cooperating Processes:** Can affect or be affected by other processes (share data or collaborate).

**Inter-Process Communication (IPC)** provides mechanisms for cooperating processes to exchange data and messages.

---

## Two Fundamental Models of IPC

```
    SHARED MEMORY MODEL                     MESSAGE PASSING MODEL
+---------+     +---------+             +---------+     +---------+
| Process |     | Process |             | Process |     | Process |
|    A    |     |    B    |             |    A    |     |    B    |
+---------+     +---------+             +---------+     +---------+
     |               |                       |               |
     v               v                       v               v
+-------------------------+             +-------------------------+
|      Shared Memory      |             |         Kernel          |
|      (User Space)       |             |  [ Message Queue / Mail]|
+-------------------------+             +-------------------------+
```

### 1. Shared Memory
- Processes establish a shared memory region in their address spaces (`shmget()`, `shmat()`).
- **Speed:** Extremely fast (data transfers at memory bus speed; no kernel intervention after setup).
- **Challenge:** Synchronization is the application's responsibility (requires Mutex/Semaphores).

### 2. Message Passing
- Processes communicate by sending and receiving messages through the kernel (`send()`, `receive()`).
- **Speed:** Slower (requires system calls, kernel buffering, and context switches).
- **Benefit:** Simple and easily works across distributed systems / networks.

---

## Common IPC Mechanisms in Modern OS

| IPC Mechanism | Description | Directionality | Scope |
| :--- | :--- | :--- | :--- |
| **Ordinary Pipe** | Unidirectional channel connecting parent & child processes (`pipe()`) | Half-duplex | Related processes |
| **Named Pipe (FIFO)** | Bi-directional pipe existing as a special file on disk (`mkfifo()`) | Full-duplex | Unrelated processes |
| **Message Queue** | Linked list of messages stored in the kernel | Asynchronous | Unrelated processes |
| **Shared Memory** | Common memory mapped region in RAM | Shared R/W | High-speed local |
| **Sockets** | Network communication endpoint (`IP:Port`) | Full-duplex | Local or Distributed (Network) |
