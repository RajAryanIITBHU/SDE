# 3. Serializability & Precedence Graphs (Conflict Serializability)

## What is Serializability?
A concurrent schedule $S$ of multiple transactions is **Serializable** if its outcome is equivalent to executing the transactions **serially (one after another)**.

---

## 1. Conflicting Operations
Two operations $I_i$ and $I_j$ in a schedule are **Conflicting** if and only if **ALL THREE conditions hold**:
1. Belong to **different transactions** ($T_i \neq T_j$).
2. Access the **same data item** $Q$.
3. **At least one operation is a WRITE** (`W(Q)`).

*(Conflicting pairs: $R_1(Q)-W_2(Q)$, $W_1(Q)-R_2(Q)$, $W_1(Q)-W_2(Q)$. Read-Read $R_1(Q)-R_2(Q)$ is NOT conflicting).*

---

## 2. Conflict Serializability & Precedence Graph Test

### How to Build a Precedence Graph (Conflict Graph):
1. Create a node for each active transaction ($T_1, T_2, \dots, T_n$).
2. Draw a directed edge $T_i \to T_j$ if $T_i$ performs an operation on item $X$ that **conflicts with and occurs BEFORE** an operation on $X$ performed by $T_j$.

### Serializability Theorem:
$$\text{A Schedule } S \text{ is Conflict Serializable} \iff \text{The Precedence Graph contains \textbf{NO CYCLES}}.$$

- If **Acyclic:** The equivalent serial schedule order is given by the **Topological Sort** of the graph.
- If **Cyclic:** The schedule is **NOT conflict serializable** (data inconsistency guaranteed).

---

## 3. View Serializability (Blind Writes)
- A broader form of serializability based on initial read, updated write, and final write equivalences.
- Every Conflict Serializable schedule is View Serializable.
- A schedule that is View Serializable but NOT Conflict Serializable must contain **Blind Writes** (writing a data item without reading it first).
