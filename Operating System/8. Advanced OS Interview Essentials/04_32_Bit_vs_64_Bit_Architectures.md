# 4. 32-Bit vs. 64-Bit Operating Systems & Architectures

## 1. Core Meaning of "32-Bit" vs. "64-Bit"

The bit-width of an architecture refers to three fundamental hardware dimensions:
1. **Register Width:** The width of the CPU's General Purpose Registers (GPRs). A 64-bit CPU can process 64-bit integers ($2^{64}-1 \approx 1.84 \times 10^{19}$) in a single clock cycle.
2. **Data Bus Width:** The number of bits fetched from RAM to the CPU in a single memory bus cycle.
3. **Address Bus Width:** The number of binary lines used to address physical memory locations (determines maximum addressable RAM).

```
           32-BIT ARCHITECTURE (x86)                  64-BIT ARCHITECTURE (x86-64 / x64)
+---------------------------------------------+   +---------------------------------------------+
| Address Bus Width: 32 bits                  |   | Address Bus Width: 64 bits (48/57 bits used)|
| General Purpose Registers: 32 bits wide     |   | General Purpose Registers: 64 bits wide     |
| Maximum Addressable RAM: 4 GB (2^32 bytes)  |   | Maximum Addressable RAM: 16 Exabytes (2^64) |
| Pointer Size: 4 bytes (32 bits)             |   | Pointer Size: 8 bytes (64 bits)             |
+---------------------------------------------+   +---------------------------------------------+
```

---

## 2. Why 32-Bit Systems are Capped at Exactly 4 GB RAM (The Math)

Each memory address corresponds to exactly **1 Byte** of RAM.

$$\text{Total Addressable Bytes} = 2^{32} \text{ bytes}$$

$$2^{32} \text{ bytes} = 2^{2} \times 2^{30} \text{ bytes} = 4 \times 1 \text{ Gigabyte} = \mathbf{4\text{ GB}}$$

- Even if a computer motherboard has 16 GB of physical RAM installed, a pure 32-bit OS and CPU **physically cannot generate addresses above $2^{32} - 1$**, leaving the remaining 12 GB inaccessible.
- **Physical Address Extension (PAE):** A legacy 36-bit extension allowing the kernel to see up to 64 GB of physical RAM, but each individual process was still restricted to a maximum 4 GB virtual address space.

---

## 3. Theoretical vs. Practical Limits of 64-Bit Systems

$$\text{Theoretical Limit} = 2^{64} \text{ bytes} = 16 \times 2^{60} \text{ bytes} = \mathbf{16\text{ Exabytes (16 Billion Gigabytes)}}$$

### Practical Implementation in Modern Processors:
- Fabricating all 64 physical address pins on a CPU chip is expensive and unnecessary for current technology.
- Modern x86-64 processors (Intel / AMD / ARM64) use:
  - **48-bit Virtual Addressing:** Supports up to **256 Terabytes of RAM** (4-level paging).
  - **57-bit Virtual Addressing (5-level paging):** Supports up to **128 Petabytes of RAM**.

---

## 4. Pointer Sizes and Data Types Comparison

| Data Type / Symbol | 32-Bit System (ILP32) | 64-Bit Linux / macOS (LP64) | 64-Bit Windows (LLP64) |
| :--- | :---: | :---: | :---: |
| `char` | 1 byte | 1 byte | 1 byte |
| `short` | 2 bytes | 2 bytes | 2 bytes |
| `int` | 4 bytes | 4 bytes | 4 bytes |
| `long` | 4 bytes | **8 bytes** | 4 bytes |
| `long long` | 8 bytes | 8 bytes | 8 bytes |
| **Pointer (`int*`, `void*`, references)** | **4 bytes (32 bits)** | **8 bytes (64 bits)** | **8 bytes (64 bits)** |

---

## 5. Backward Compatibility (WoW64 and Multilib)

- **Can a 64-bit OS run 32-bit software?**
  - **Yes.** 64-bit operating systems include 32-bit subsystem layers (e.g., **WoW64 - Windows 32-bit on Windows 64-bit**, or 32-bit multi-arch compatibility libraries in Linux) that translate 32-bit system calls, structures, and pointers.
- **Can a 32-bit OS run 64-bit software?**
  - **No.** A 32-bit OS and CPU cannot execute 64-bit machine instructions because it lacks the required 64-bit registers (`RAX`, `RBX`, `R8`–`R15`) and wider instruction decoders.

---

## 6. Master Summary Table

| Metric | 32-Bit System (x86) | 64-Bit System (x86-64 / ARM64) |
| :--- | :--- | :--- |
| **Physical RAM Cap** | 4 GB | 16 Exabytes (Practically 256 TB+) |
| **Pointer Size** | 4 Bytes (32 bits) | 8 Bytes (64 bits) |
| **General Purpose Registers** | 8 Registers (EAX, EBX, ECX, EDX...) | 16 Registers (RAX, RBX, R8–R15...) |
| **Default Virtual Address Space** | 4 GB (2 GB User / 2 GB Kernel) | 256 TB (128 TB User / 128 TB Kernel) |
| **Arithmetic Performance** | 64-bit operations require multiple CPU cycles | 64-bit operations executed in 1 CPU cycle |
| **Current Industry Status** | Legacy / Microcontrollers | Ubiquitous Standard |
