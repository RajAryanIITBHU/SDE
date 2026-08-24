# 1. Deadlock Management in DBMS: Wait-Die & Wound-Wait

When 2PL locking is used, concurrent transactions can experience deadlocks. DBMS engines handle deadlocks using timestamp-based prevention schemes:

---

## 1. Wait-Die Scheme (Non-Preemptive Prevention)

Based on transaction age timestamps ($TS(T_i)$):

- Suppose transaction $T_i$ requests a lock on a data item held by $T_j$:
- **If $T_i$ is OLDER than $T_j$ ($TS(T_i) < TS(T_j)$):**
  - $T_i$ is allowed to **WAIT**.
- **If $T_i$ is YOUNGER than $T_j$ ($TS(T_i) > TS(T_j)$):**
  - $T_i$ **DIES (Aborts and rolls back)** with its original timestamp preserved.

$$\text{Mnemonic: "Old waits, Young dies."}$$

---

## 2. Wound-Wait Scheme (Preemptive Prevention)

- Suppose transaction $T_i$ requests a lock held by $T_j$:
- **If $T_i$ is OLDER than $T_j$ ($TS(T_i) < TS(T_j)$):**
  - $T_i$ **WOUNDS (Preempts/Aborts)** $T_j$ and seizes the lock immediately.
- **If $T_i$ is YOUNGER than $T_j$ ($TS(T_i) > TS(T_j)$):**
  - $T_i$ is allowed to **WAIT**.

$$\text{Mnemonic: "Old wounds young, Young waits for old."}$$

---

## Comparison Table

| Feature | Wait-Die Scheme | Wound-Wait Scheme |
| :--- | :--- | :--- |
| **Preemption** | Non-preemptive (No active transactions aborted) | **Preemptive** (Older transaction preempts younger) |
| **Number of Aborts** | Higher abort rate | **Fewer aborts** (Preferred in modern engines) |
| **Starvation** | Avoided (Aborted transaction keeps original timestamp) | Avoided (Timestamps preserved) |
