# 2. Resource Allocation Graph (RAG)

## What is a Resource Allocation Graph (RAG)?
A **Resource Allocation Graph (RAG)** is a directed graph $(V, E)$ used to visually represent the resource allocation state of the system:
- **Vertices $V$:**
  - **Process Nodes (Circles):** $P = \{P_1, P_2, \dots, P_n\}$
  - **Resource Nodes (Rectangles):** $R = \{R_1, R_2, \dots, R_m\}$ (Dots inside represent resource instances).
- **Edges $E$:**
  - **Request Edge:** Directed edge from Process to Resource ($P_i \to R_j$).
  - **Assignment Edge:** Directed edge from Resource instance to Process ($R_j \to P_i$).
  - **Claim Edge (Dashed):** Indicates $P_i$ *may* request $R_j$ in the future ($P_i \dashrightarrow R_j$).

---

## Cycle vs. Deadlock Rules (Key Interview Takeaway)

```
+------------------------------------------------------------------+
| SINGLE-INSTANCE Resources | Cycle in RAG  ===>  DEFINITE DEADLOCK|
+------------------------------------------------------------------+
| MULTI-INSTANCE Resources  | Cycle in RAG  ===>  MAYBE DEADLOCK   |
|                           | (Cycle is necessary, not sufficient) |
+------------------------------------------------------------------+
```

### 1. Single-Instance Resource Type
- Every resource rectangle has exactly 1 dot.
- **A cycle in the graph is both necessary and sufficient for deadlock.** (Cycle $\iff$ Deadlock).

### 2. Multi-Instance Resource Type
- Resource rectangles contain multiple dots (instances).
- **A cycle does NOT guarantee a deadlock** because other processes outside the cycle holding instances of the same resource might finish and release them.
- Banker's Safety Algorithm must be executed to confirm deadlock.
