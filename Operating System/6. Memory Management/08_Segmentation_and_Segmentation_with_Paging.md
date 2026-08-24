# 8. Segmentation & Segmentation with Paging

## 1. What is Segmentation?
- **Paging** is a **hardware-centric** view (fixed arbitrary 4 KB chunks without semantic meaning).
- **Segmentation** is a **programmer-centric / user-centric** view: a program is viewed as a collection of logical variable-length modules called **Segments** (Code, Stack, Heap, Global Symbol Table, Main Routine).

---

## Logical Address Translation in Segmentation

A Logical Address in segmentation consists of a two-tuple: `(s, d)`
- $s$ = Segment Number
- $d$ = Offset within segment

### The Segment Table:
Each entry contains two fields:
1. **Base (Physical Start Address):** The starting physical address of the segment in RAM.
2. **Limit (Length):** The exact length of the segment.

```
       Logical Address: (s, d)
                 |
                 v
           [ SEGMENT TABLE ]
                 |
        Is Offset d < Limit?
        /                  \
       v (Yes)              v (No)
 Physical Address =       TRAP: Segment Limit Violation
 Base + Offset d
```

---

## Paging vs. Segmentation Comparison

| Feature | Paging | Segmentation |
| :--- | :--- | :--- |
| **Block Size** | Fixed size (e.g., 4 KB) | Variable size (matches logical unit) |
| **Visibility** | Invisible to programmer (OS handles it) | Visible to programmer / compiler |
| **Internal Fragmentation** | Possible in last page | **Zero (0%)** |
| **External Fragmentation** | **Zero (0%)** | **Possible** (variable size segments) |
| **Table Details** | Page Table (Page $\to$ Frame) | Segment Table (Base + Limit) |

---

## 2. Segmentation with Paging (Combined Scheme)
To get the logical organization benefits of segmentation without external fragmentation:
1. Divide program into logical **Segments**.
2. Instead of allocating segments contiguously in RAM, **Page each segment** into fixed 4 KB pages!
3. Used by modern architectures (x86 protected mode).
