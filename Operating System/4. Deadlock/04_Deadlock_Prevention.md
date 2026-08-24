# 4. Deadlock Prevention (Eliminating Coffman Conditions)

Deadlock Prevention works by imposing structural constraints so that at least one of the four Coffman conditions can **never** occur:

---

## 1. Eliminating "Mutual Exclusion"
- **Method:** Make all resources shareable (read-only access).
- **Feasibility:** **Impossible in practice** for inherently non-shareable hardware resources like Printers, Tape drives, or write-locks.

---

## 2. Eliminating "Hold and Wait"
- **Protocol 1 (Conservative):** A process must request and be allocated **ALL required resources before execution starts**.
  - *Downside:* Very low resource utilization (a resource needed at the end is held idle throughout).
- **Protocol 2:** A process can request additional resources **only when it holds zero resources** (must release current resources first before requesting a new set).
  - *Downside:* Starvation risk for processes requiring multiple popular resources.

---

## 3. Eliminating "No Preemption"
- **Protocol:** If a process $P_i$ holding resources requests another resource that is currently busy:
  - All resources currently held by $P_i$ are **preempted** (forcibly released).
  - $P_i$ is placed in a waiting state and restarted only when it can re-acquire all its old and new resources.
- **Feasibility:** Practical only for easily state-saveable resources (CPU registers, RAM page frames), but not for I/O devices (cannot preempt a half-printed page).

---

## 4. Eliminating "Circular Wait" (Most Practical Prevention Strategy)
- **Protocol:** Impose a **global total ordering** on all resource types using a one-to-one mapping function $F: R \to \mathbb{N}$.
  - e.g., $F(\text{Tape Drive}) = 1$, $F(\text{Disk}) = 5$, $F(\text{Printer}) = 12$.
- **Rule:** A process can only request resources in **strictly increasing order** of their enumeration values ($F(R_j) > F(R_i)$).
- **Proof:** Circular wait requires a cycle where $F(R_1) < F(R_2) < \dots < F(R_n) < F(R_1)$, which is a mathematical impossibility ($x < x$).
