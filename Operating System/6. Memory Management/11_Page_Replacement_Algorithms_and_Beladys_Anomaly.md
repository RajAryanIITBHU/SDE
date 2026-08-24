# 11. Page Replacement Algorithms & Belady's Anomaly

When a page fault occurs and **no free frames exist in RAM**, the OS must choose an existing page to evict: a **Victim Page**.

---

## 1. FIFO (First-In, First-Out) Page Replacement
- **Strategy:** Evicts the page that has been in RAM the **longest amount of time**.
- **Drawback:** May evict a heavily used variable or library simply because it was loaded early.
- **Suffers from Belady's Anomaly!**

---

## 2. Belady's Anomaly (High-Frequency Interview Question)

### What is Belady's Anomaly?
**Belady's Anomaly** is the phenomenon where **increasing the number of page frames results in an INCREASE in the number of page faults** for certain reference strings under FIFO.

### Classic Counter-Example:
Reference String: `1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5`
- With **3 Frames:** Produces **9 Page Faults**.
- With **4 Frames:** Produces **10 Page Faults** (More frames $\to$ More faults!).

*Note: Stack-based algorithms (LRU, Optimal) are mathematically proven NEVER to suffer from Belady's anomaly.*

---

## 3. Optimal Page Replacement (OPT / MIN / Belady's Algorithm)
- **Strategy:** Replace the page that **will not be used for the longest period of time in the FUTURE**.
- **Optimality:** Produces the lowest possible page fault rate of any algorithm.
- **Feasibility:** Impossible to implement in real general-purpose OS (requires clairvoyant knowledge of the future). Used as a theoretical benchmark.

---

## 4. Least Recently Used (LRU) Page Replacement
- **Strategy:** Approximates the optimal algorithm by looking backward in time: replace the page that **has not been used for the longest period in the PAST**.
- **Performance:** Excellent approximation of OPT; does not suffer from Belady's anomaly.
- **Implementation:** Requires hardware support (Counters or a Doubly Linked List Stack moved on every memory reference).
