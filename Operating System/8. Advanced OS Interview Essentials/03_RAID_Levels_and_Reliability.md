# 3. RAID Levels & Storage Reliability

## What is RAID?
**RAID** stands for **Redundant Array of Independent Disks**.

It is a data storage virtualization technology that combines **multiple physical hard drives into one single logical drive** to achieve:
1. **Higher Performance (Speed)** via Data Striping.
2. **High Reliability / Fault Tolerance** via Data Mirroring or Parity.

---

## The 5 Essential RAID Levels Compared

```
      RAID 0 (Striping)                 RAID 1 (Mirroring)
+--------------+--------------+   +--------------+--------------+
|    Disk 0    |    Disk 1    |   |    Disk 0    |    Disk 1    |
+--------------+--------------+   +--------------+--------------+
|   Block A1   |   Block A2   |   |   Block A1   |   Block A1   |
|   Block A3   |   Block A4   |   |   Block A2   |   Block A2   |
|   Block A5   |   Block A6   |   |   Block A3   |   Block A3   |
+--------------+--------------+   +--------------+--------------+
  (Max Speed, 0 Redundancy)          (100% Duplicate Copy)

========================================================================

                 RAID 5 (Block Striping with Distributed Parity)
+--------------+--------------+--------------+--------------+
|    Disk 0    |    Disk 1    |    Disk 2    |    Disk 3    |
+--------------+--------------+--------------+--------------+
|   Block A1   |   Block A2   |   Block A3   |  Parity Ap   |
|   Block B1   |   Block B2   |  Parity Bp   |   Block B3   |
|   Block C1   |  Parity Cp   |   Block C2   |   Block C3   |
|  Parity Dp   |   Block D1   |   Block D2   |   Block D3   |
+--------------+--------------+--------------+--------------+
  (Tolerates 1 Disk Failure; Parity distributed across all disks)
```

---

## Detailed Breakdown of RAID Levels

### 1. RAID 0 (Striping)
- **Mechanism:** Data is split into chunks (stripes) and written across all disks simultaneously in parallel.
- **Redundancy / Fault Tolerance:** **Zero (0%)**. If 1 disk fails, **ALL data is lost**.
- **Usable Capacity:** $N \times \text{Disk Size}$ (100% storage efficiency).
- **Use Case:** High-speed video editing / gaming cache where data loss is not critical.

### 2. RAID 1 (Mirroring)
- **Mechanism:** Exact duplicate copy of data is written to two identical disks simultaneously.
- **Fault Tolerance:** Can survive **1 disk failure** without any data loss.
- **Usable Capacity:** $\frac{N}{2} \times \text{Disk Size}$ (50% storage overhead / expensive).
- **Use Case:** OS boot drives, financial databases.

### 3. RAID 5 (Block Striping + Distributed Parity)
- **Mechanism:** Data blocks are striped across disks, and a **Parity Block** ($\text{Parity} = A_1 \oplus A_2 \oplus A_3$) is calculated and distributed cyclically across all disks.
- **Minimum Disks Required:** **3 Disks**.
- **Fault Tolerance:** Can survive **any 1 disk failure**. If Disk 1 dies, missing data is reconstructed using XOR: $A_1 = A_2 \oplus A_3 \oplus A_p$.
- **Usable Capacity:** $(N - 1) \times \text{Disk Size}$.
- **Use Case:** Standard enterprise file servers and cloud storage.

### 4. RAID 6 (Dual Distributed Parity)
- **Mechanism:** Similar to RAID 5, but calculates **two independent parity blocks** ($P$ and $Q$).
- **Minimum Disks Required:** **4 Disks**.
- **Fault Tolerance:** Can survive **up to 2 simultaneous disk failures**!
- **Usable Capacity:** $(N - 2) \times \text{Disk Size}$.
- **Use Case:** Mission-critical enterprise archives.

### 5. RAID 10 (Nested RAID 1 + 0 / Striped Mirrors)
- **Mechanism:** Combines the speed of RAID 0 striping with the safety of RAID 1 mirroring.
- **Minimum Disks Required:** **4 Disks**.
- **Fault Tolerance:** Can survive multiple disk failures as long as no two failed disks belong to the same mirrored pair.
- **Use Case:** High-traffic transactional databases.

---

## Master Comparison Table

| RAID Level | Primary Technique | Min Disks | Fault Tolerance | Usable Capacity | Read Speed | Write Speed |
| :---: | :--- | :---: | :---: | :---: | :---: | :---: |
| **RAID 0** | Striping | 2 | **0 (None)** | $N$ | Very High | Very High |
| **RAID 1** | Mirroring | 2 | 1 Disk | $\frac{N}{2}$ | High | Normal |
| **RAID 5** | Striping + Distributed Parity | 3 | 1 Disk | $N - 1$ | Very High | Moderate (Parity calc) |
| **RAID 6** | Striping + Dual Parity | 4 | **2 Disks** | $N - 2$ | Very High | Slower (2 parities) |
| **RAID 10** | Striped Mirrors | 4 | Up to 1 per pair | $\frac{N}{2}$ | Extremely High | High |
