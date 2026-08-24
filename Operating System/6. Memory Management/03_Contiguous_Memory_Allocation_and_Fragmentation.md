# 3. Contiguous Memory Allocation & Fragmentation

## What is Contiguous Allocation?
In **Contiguous Memory Allocation**, each process is allocated a **single, contiguous block** of physical memory.

---

## 1. Fixed Partitioning (Static MFT - Multiprogramming with Fixed Tasks)
- RAM is divided into a fixed number of non-overlapping partitions of fixed sizes at boot time.
- **Problem: Internal Fragmentation:** If a process needs 15 MB and is placed into a 32 MB partition, $32 - 15 = 17\text{ MB}$ inside the partition is completely wasted.
- **Problem:** Fixed degree of multiprogramming.

---

## 2. Variable Partitioning (Dynamic MVT - Multiprogramming with Variable Tasks)
- Partitions are created dynamically to match the exact size requested by a process.
- **No Internal Fragmentation.**
- **Problem: External Fragmentation:** As processes terminate and leave RAM, free memory is broken into many small, non-contiguous holes.
  - Total free memory might be 50 MB, but if it is scattered as five 10 MB holes, a new 30 MB process **cannot be allocated**.

---

## Contiguous Allocation Placement Algorithms

| Algorithm | Strategy | Pros / Cons |
| :--- | :--- | :--- |
| **First Fit** | Allocates the **first hole** that is big enough (scans from beginning). | Fastest algorithm; good overall memory utilization. |
| **Best Fit** | Allocates the **smallest hole** that is big enough (scans entire list). | Leaves tiny, unusable leftover holes; creates severe external fragmentation. |
| **Worst Fit** | Allocates the **largest available hole** (scans entire list). | Produces the largest leftover hole (more likely to be usable by other processes), but slow. |
| **Next Fit** | Like First Fit, but starts search from the **location of the last allocation**. | Avoids clustering holes at the start of memory. |

---

## Solutions to External Fragmentation

1. **Compaction (Defragmentation):** Shuffle all occupied memory partitions to one end of RAM to combine all scattered holes into one large free block.
   - *Requirement:* Dynamic relocation with base/limit registers.
   - *Cost:* Extremely high CPU / memory bus overhead.
2. **Non-Contiguous Allocation (Paging / Segmentation):** The modern, permanent solution!
