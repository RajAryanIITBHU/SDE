# 1. Memory Basics and Memory Hierarchy

## What is Memory in a Computer System?
**Memory** is a collection of storage cells, each with a unique physical address, used to hold program instructions and data during execution.

---

## Memory Hierarchy (Speed vs. Cost vs. Size)

```
        /\          LEVEL 0: CPU Registers (Fastest, Smallest, Highest Cost/bit)
       /  \         LEVEL 1: CPU Cache (L1, L2, L3 SRAM)
      /    \        LEVEL 2: Main Memory (DRAM / RAM)
     /      \       LEVEL 3: Solid State Drive (SSD / Flash NVMe)
    /        \      LEVEL 4: Hard Disk Drive (HDD / Magnetic Storage)
   /__________\     LEVEL 5: Tertiary Backup (Optical / Magnetic Tape)
  (Slowest, Largest, Lowest Cost/bit)
```

---

## Standard Memory Units

| Unit | Value in Bytes | Equivalent |
| :--- | :--- | :--- |
| **Bit (b)** | $0$ or $1$ | Smallest binary unit |
| **Byte (B)** | $8\text{ bits}$ | $1\text{ Byte}$ |
| **Kilobyte (KB)** | $2^{10}\text{ Bytes}$ | $1,024\text{ Bytes}$ |
| **Megabyte (MB)** | $2^{20}\text{ Bytes}$ | $1,024\text{ KB}$ |
| **Gigabyte (GB)** | $2^{30}\text{ Bytes}$ | $1,024\text{ MB}$ |
| **Terabyte (TB)** | $2^{40}\text{ Bytes}$ | $1,024\text{ GB}$ |
| **Petabyte (PB)** | $2^{50}\text{ Bytes}$ | $1,024\text{ TB}$ |

---

## Why is Memory Management Needed?
1. **Dynamic Relocation:** Programs are compiled assuming they start at address 0; the OS maps them anywhere in physical RAM.
2. **Protection:** Prevents one process from accessing or corrupting memory belonging to other processes or the kernel.
3. **Sharing:** Allows shared libraries (`.so`, `.dll`) and shared memory segments.
4. **Logical Organization:** Enables modular division of code into segments (stack, heap, code).
5. **Physical Organization:** Automatically moves pages between fast RAM and secondary storage (Virtual Memory).
