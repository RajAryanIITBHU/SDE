# 2. Types of Operating Systems

Here is a clear comparison of all major types of Operating Systems:

---

## 1. Batch Operating System
- **How it works:** Similar jobs are collected into batches by an operator and executed sequentially on the CPU without direct user interaction.
- **Advantage:** Good CPU utilization for large repetitive tasks.
- **Disadvantage:** No user interaction; if one job gets stuck in an infinite loop, all following jobs wait.
- **Examples:** IBM OS/360, Payroll processing systems.

---

## 2. Multiprogramming Operating System
- **How it works:** Multiple programs reside in RAM simultaneously. When the currently running program waits for I/O, the OS switches the CPU to another ready program.
- **Key Metric:** Maximizes **CPU Utilization** (prevents CPU from sitting idle during I/O).

---

## 3. Multitasking / Time-Sharing Operating System
- **How it works:** An extension of multiprogramming. The CPU switches between tasks rapidly using a fixed **time quantum** (e.g., 10–50 ms), giving users the illusion that multiple programs run at the same time.
- **Key Metric:** Minimizes **Response Time** and provides interactive responsiveness.
- **Examples:** Windows 10/11, macOS, Linux, Ubuntu.

---

## 4. Real-Time Operating System (RTOS)
- **How it works:** Built for systems where processing must be completed within strict, predictable **deadlines**.
- **Two Categories:**
  - **Hard RTOS:** Missing a deadline causes total system failure (e.g., Missile guidance, Airbag deployment, Pacemakers).
  - **Soft RTOS:** Missing a deadline degrades performance but is tolerable (e.g., Live video streaming, Online gaming).
- **Examples:** VxWorks, QNX, FreeRTOS.

---

## 5. Distributed Operating System
- **How it works:** Multiple independent physical computers (nodes) are connected over a network and coordinated by a single OS, appearing as a single unified computer to users.
- **Advantage:** High fault tolerance, easy scalability, load sharing.
- **Examples:** LOCUS, Amoeba.

---

## 6. Clustered Operating System
- **How it works:** Groups multiple independent servers/computers into a single high-availability cluster sharing a storage area network (SAN).
- **Two Types:**
  - **Asymmetric Clustering:** One machine runs applications while another stays in standby mode monitoring failures.
  - **Symmetric Clustering:** All nodes run applications and monitor each other concurrently.

---

## Quick Summary Comparison Table

| OS Type | Primary Goal | CPU Switching Trigger |
| :--- | :--- | :--- |
| **Batch OS** | High throughput for offline jobs | When job completes |
| **Multiprogramming** | Maximum CPU utilization | When current process blocks for I/O |
| **Multitasking (Time-Sharing)** | Minimal user response time | Timer interrupt (Time slice expiry) |
| **Real-Time (RTOS)** | Guaranteed strict deadlines | Real-time event / High-priority interrupt |
| **Distributed OS** | Shared resources across network | Distributed RPC / Message passing |
