# 5. Banker's Algorithm for Deadlock Avoidance

## Why is it Called Banker's Algorithm?
Developed by Edsger Dijkstra, the algorithm is modeled on a small-town banking system: the bank never allocates its cash in a way that prevents it from satisfying the cash demands of at least one customer to completion.

---

## Data Structures Used

For $n$ processes and $m$ resource types:
1. **`Available[m]`:** Vector of length $m$. If `Available[j] = k`, $k$ instances of resource $R_j$ are free.
2. **`Max[n][m]`:** $n \times m$ matrix. `Max[i][j] = k` means process $P_i$ may request at most $k$ instances of $R_j$.
3. **`Allocation[n][m]`:** $n \times m$ matrix. `Allocation[i][j] = k` means $P_i$ currently holds $k$ instances of $R_j$.
4. **`Need[n][m]`:** $n \times m$ matrix. Remaining resources needed by process $P_i$:
   $$\text{Need}[i][j] = \text{Max}[i][j] - \text{Allocation}[i][j]$$

---

## 1. Safety Algorithm

Tests whether a system state is **Safe**:

```
1. Initialize Work = Available, Finish[i] = false for all i = 0..n-1.
2. Find an index i such that:
     Finish[i] == false AND Need[i] <= Work
   If no such i exists, goto step 4.
3. Work = Work + Allocation[i]
   Finish[i] = true
   Goto step 2.
4. If Finish[i] == true for all i:
     SYSTEM IS IN SAFE STATE (A safe sequence exists)
   Else:
     SYSTEM IS IN UNSAFE STATE (Deadlock possible)
```

---

## 2. Resource-Request Algorithm

When process $P_i$ makes a request vector $\text{Request}_i$:

1. If $\text{Request}_i \le \text{Need}_i$, goto step 2. Else error (exceeded max claim).
2. If $\text{Request}_i \le \text{Available}$, goto step 3. Else $P_i$ must wait (resources not free).
3. **Pretend to allocate:**
   $$\text{Available} = \text{Available} - \text{Request}_i$$
   $$\text{Allocation}_i = \text{Allocation}_i + \text{Request}_i$$
   $$\text{Need}_i = \text{Need}_i - \text{Request}_i$$
4. Run the **Safety Algorithm**:
   - If **Safe** $\to$ Grant resources to $P_i$.
   - If **Unsafe** $\to$ Roll back pretend allocation; $P_i$ must wait.
