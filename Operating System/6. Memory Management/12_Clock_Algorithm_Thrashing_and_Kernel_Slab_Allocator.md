# 12. Clock (Second Chance) Algorithm, Thrashing & Kernel Slab Allocator

## 1. Second Chance (Clock) Page Replacement Algorithm
Because pure LRU requires expensive hardware tracking on every memory access, modern operating systems use the **Clock Algorithm (Second Chance)** to approximate LRU:

- Uses a circular buffer of frames and a **Referenced Bit ($R$)** in each PTE.
- A pointer moves around the circular list like a clock hand:
  1. Inspect the frame pointed to by the hand.
  2. If its $R\text{-bit} == 1$, give it a "second chance": set $R = 0$ and advance hand to next frame.
  3. If its $R\text{-bit} == 0$, select this page as the **victim** and advance hand.

---

## 2. What is Thrashing?
**Thrashing** is a pathological system state where the CPU spends **more time swapping pages in and out of disk than executing actual user instructions**.

```
CPU
Util %
 100 |          /\
     |         /  \
     |        /    \
     |       /      \  <--- THRASHING OCCURS HERE!
     |      /        \
   0 +---------------------------------
       Low         Optimal       High
             Degree of Multiprogramming
```

### Why Thrashing Happens:
$$\text{Sum of Working Sets of all active processes} > \text{Total Physical RAM Frames}$$

### Techniques to Prevent Thrashing:
1. **Working Set Model (Peter Denning):**
   - Define a working set parameter $\Delta$ (time window).
   - $\text{Working Set}(WSS_i)$ = set of unique pages referenced by process $P_i$ in last $\Delta$ memory references.
   - If $\sum WSS_i > \text{Total RAM Frames}$, the OS suspends/swaps out an entire process to free frames.
2. **Page Fault Frequency (PFF) Strategy:**
   - If a process's page fault rate exceeds an upper threshold $\to$ allocate more frames to it.
   - If page fault rate drops below a lower threshold $\to$ reclaim frames from it.

---

## 3. Kernel Memory Allocation: Slab Allocator
The kernel frequently allocates and deallocates small, fixed-size data structures (PCBs, semaphores, file descriptors, inodes). Using general paging or buddy systems creates fragmentation and overhead.

- **Slab Allocator:** Pre-allocates caches composed of contiguous pages (**Slabs**).
- Each cache stores pre-initialized objects of a specific type (e.g., `mm_struct`, `inode_cache`).
- **Benefits:** Zero internal fragmentation for kernel structures; ultra-fast object allocation without initialization overhead.
