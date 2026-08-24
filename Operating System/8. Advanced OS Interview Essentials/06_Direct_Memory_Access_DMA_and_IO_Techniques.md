# 6. Direct Memory Access (DMA) & I/O Communication Techniques

## 3 Ways Computers Communicate with I/O Devices

```
 1. PROGRAMMED I/O (POLLING)     2. INTERRUPT-DRIVEN I/O           3. DIRECT MEMORY ACCESS (DMA)
+-----+     Continuously checks  +-----+     CPU initiates I/O     +-----+     CPU tells DMA controller
| CPU | <--------------------->  | CPU | <---------------------+   | CPU |     to transfer block of 100 MB
+-----+     status register      +-----+     Device sends      |   +-----+                 |
   |        (100% CPU wasted)       |        Interrupt when    |      |                    v
   v                                v        data ready        |      |             +--------------+
+--------+                       +--------+                    |      |             |     DMA      |
| Device |                       | Device | -------------------+      |             |  Controller  |
+--------+                       +--------+                           |             +--------------+
                                                                      |                    |
                                                                      | (CPU free to       | Transfers data
                                                                      |  do other work)    | directly to RAM
                                                                      v                    v
                                                                 +----------------------------+
                                                                 |      Main Memory (RAM)     |
                                                                 +----------------------------+
```

---

## 1. Programmed I/O (Polling / Busy-Waiting)
- CPU continuously reads a device status register in a tight loop (`while (!ready);`).
- **Drawback:** Wastes 100% of CPU cycles waiting for slow hardware.

## 2. Interrupt-Driven I/O
- CPU issues an I/O command and switches to other tasks. When device is ready, it raises a hardware **Interrupt**.
- **Drawback:** Inefficient for high-speed devices (transferring a 1 GB file byte-by-byte generates 1 billion interrupts, overwhelming the CPU).

## 3. Direct Memory Access (DMA)
- A specialized hardware controller (**DMA Controller**) transfers entire blocks of data **directly between device and RAM** without passing through CPU registers.
- **Process:**
  1. CPU writes source address, destination address, and byte count to the DMA controller.
  2. DMA controller transfers the entire data buffer directly to/from RAM.
  3. DMA controller generates a **single interrupt** to the CPU only when the entire multi-megabyte transfer is finished.

---

## DMA Transfer Modes: Cycle Stealing vs. Burst Mode
1. **Burst Mode:** DMA takes complete control of the system memory bus until the entire data block transfer is finished.
2. **Cycle Stealing:** DMA takes control of the memory bus for **1 memory cycle** at a time between CPU memory accesses, avoiding stalling the CPU.
