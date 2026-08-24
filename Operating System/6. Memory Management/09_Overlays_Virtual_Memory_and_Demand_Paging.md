# 9. Overlays, Virtual Memory & Demand Paging

## 1. What were Overlays? (Historical Context)
- In early computers without virtual memory, if a program size was 10 MB and physical RAM was only 4 MB:
- The programmer manually partitioned code into independent modules (**Overlays**) and wrote code to overwrite (overlay) inactive routines in RAM as needed.
- **Flaw:** High programmer burden; completely obsolete today due to Virtual Memory.

---

## 2. Virtual Memory
**Virtual Memory** is a memory management technique that creates an illusion of a massive, contiguous address space (e.g., 64-bit address space), allowing programs **larger than physical RAM** to execute seamlessly.

### Core Principle:
- Only the **currently active pages** of a process need to be in physical RAM at any given moment. Inactive pages reside on secondary storage (Swap Space / Page File).

---

## 3. Demand Paging
**Demand Paging** is the implementation of Virtual Memory where a page is **loaded into RAM ONLY when it is referenced/demanded** during execution (lazy loading).

- **Pure Demand Paging:** Start executing a process with **zero pages in RAM**. The first instruction execution immediately triggers a page fault to bring in page 0.

### Advantages:
1. Less I/O needed (do not load unused functions or error handlers).
2. Less physical RAM used per process.
3. Allows more concurrent processes $\to$ higher **Degree of Multiprogramming**.
4. A program's size is no longer constrained by the physical size of RAM.
