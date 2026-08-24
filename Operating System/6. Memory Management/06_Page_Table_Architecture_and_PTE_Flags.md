# 6. Page Table Architecture & Page Table Entry (PTE) Flags

## What is a Page Table?
A **Page Table** is an in-memory data structure maintained by the OS for every process that maps **Page Numbers ($p$) $\to$ Frame Numbers ($f$)**.

- **Page Table Base Register (PTBR):** A CPU control register (e.g., `CR3` on x86) pointing to the physical start address of the active process's page table in RAM.

---

## Fields in a Page Table Entry (PTE)

A single entry in the page table contains the Frame Number plus several hardware **control and protection bits**:

```
+----+----+----+----+----+----+------------------------------------+
| V  | R/W| U/S| D  | A  | PWT|         Frame Number (f)           |
+----+----+----+----+----+----+------------------------------------+
```

| Flag / Bit | Name | Description |
| :--- | :--- | :--- |
| **Valid / Present Bit (V)** | Present/Absent Bit | `1` if page is present in physical RAM; `0` if page is on disk (triggers a **Page Fault**). |
| **Read / Write Bit (R/W)** | Protection Bit | `1` = Read and Write allowed; `0` = Read-Only (e.g., Code segment). |
| **User / Supervisor (U/S)** | Privilege Bit | `1` = User mode can access; `0` = Kernel mode only. |
| **Dirty Bit (D) / Modified** | Modified Bit | `1` if page was written to while in RAM. If `1`, it must be written back to disk before replacement. |
| **Accessed / Referenced (A)**| Referenced Bit | `1` if page was read or written recently. Used by page replacement algorithms (LRU / Clock). |
| **Caching Disabled (PCD)** | Cache Inhibit Bit | `1` prevents CPU from caching this page (used for memory-mapped hardware I/O). |
