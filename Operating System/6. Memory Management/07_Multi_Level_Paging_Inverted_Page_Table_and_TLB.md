# 7. Multi-Level Paging, Inverted Page Table & TLB

## 1. Why Multi-Level Paging?
In a 32-bit system with 4 KB pages:
$$\text{Number of Pages} = \frac{2^{32}}{2^{12}} = 2^{20} = 1\text{ Million Pages}$$
$$\text{Page Table Size per Process} = 2^{20} \times 4\text{ Bytes (PTE)} = 4\text{ MB per process!}$$
In a 64-bit system, a single flat page table would require **thousands of Terabytes**!

- **Solution: Multi-Level Paging (Hierarchical Paging):** Page the page table itself. Only allocate inner page tables for address regions that the process actually uses (sparse allocation).

```
32-Bit Logical Address (Two-Level Paging):
+--------------------+--------------------+--------------------+
|  Outer Page (p1)   |  Inner Page (p2)   |     Offset (d)     |
|      10 bits       |      10 bits       |      12 bits       |
+--------------------+--------------------+--------------------+
```

---

## 2. Inverted Page Table
- **Concept:** Instead of having one page table per process, have **ONE global page table for the entire physical RAM**.
- Has exactly one entry per **Physical Frame** in RAM.
- **Entry Structure:** `(Process_ID, Page_Number) -> Frame_Number`.
- **Advantage:** Saves massive amounts of RAM.
- **Disadvantage:** Slower lookups (requires linear search or hash table) and makes shared memory harder to implement.

---

## 3. Translation Lookaside Buffer (TLB) & EMAT

A **TLB** is an ultra-fast associative hardware cache on the CPU chip storing recent `Page -> Frame` translations.

```
                  Logical Address: (p, d)
                            |
                     +------+------+
                     |             |
                     v             v
                [ TLB HIT ]   [ TLB MISS ]
                     |             |
             Get Frame Number      Access Page Table in RAM
             from TLB Cache        (Costs extra RAM access)
```

### Effective Memory Access Time (EMAT) Formula

$$\text{EMAT} = h \cdot (t + m) + (1 - h) \cdot (t + 2m)$$

Where:
- $h$ = TLB Hit Ratio (e.g., $95\% = 0.95$)
- $t$ = TLB lookup time (e.g., $2\text{ ns}$)
- $m$ = Main memory (RAM) access time (e.g., $100\text{ ns}$)
- *(For a 2-Level Page table miss, it takes $t + 3m$)*.
