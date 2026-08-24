# 5. Two-Phase Locking (2PL) & Timestamp Ordering Protocols

To guarantee Conflict Serializability automatically, the DBMS Concurrency Manager uses concurrency protocols:

---

## 1. Two-Phase Locking Protocol (2PL)

A transaction locks data items before accessing them. **Lock Modes:**
- **Shared Lock ($S$):** For Read-Only access (`lock-S(X)`). Multiple transactions can hold Shared locks concurrently.
- **Exclusive Lock ($X$):** For Read/Write access (`lock-X(X)`). Only one transaction can hold an Exclusive lock.

### The Two Phases of 2PL:
1. **Growing (Expanding) Phase:** Transaction **acquires locks** as needed. It **CANNOT release any locks**.
2. **Shrinking (Contracting) Phase:** Transaction **releases locks**. It **CANNOT acquire any new locks**.

$$\text{Lock Point: The exact moment when the transaction holds its maximum number of locks.}$$

```
Number of
Locks Held
   ^               Lock Point
   |                  /\
   |   Growing       /  \    Shrinking
   |    Phase       /    \     Phase
   |   (Acquire)   /      \  (Release)
 0 +--------------+--------+-----------> Time
```

---

## 4 Variations of 2PL

| 2PL Variant | Rule | Guarantees |
| :--- | :--- | :--- |
| **Basic 2PL** | Normal Growing & Shrinking phases | Conflict Serializability (May suffer from Deadlocks & Cascading aborts) |
| **Conservative 2PL (Static)** | Acquires **ALL locks before execution starts** | **Deadlock-Free**, but low concurrency |
| **Strict 2PL** | Basic 2PL + All **Exclusive ($X$) locks held until COMMIT** | Prevents Dirty Reads & Cascading Aborts |
| **Rigorous 2PL** | Basic 2PL + **ALL locks ($S$ and $X$) held until COMMIT** | Strict + Easy rollback (Most widely used in practice) |

---

## 2. Timestamp Ordering Protocol (TO)

Each transaction $T_i$ is assigned a unique, monotonically increasing timestamp $TS(T_i)$ upon arrival.
- Each data item $Q$ maintains two timestamps:
  - $R\text{-timestamp}(Q)$: Largest timestamp of any transaction that successfully executed `read(Q)`.
  - $W\text{-timestamp}(Q)$: Largest timestamp of any transaction that successfully executed `write(Q)`.

### Thomas Write Rule (Optimization of Timestamp Protocol):
- If $T_i$ attempts to execute `write(Q)` and $TS(T_i) < W\text{-timestamp}(Q)$:
- Instead of aborting $T_i$, simply **IGNORE the write operation** because a newer write has already taken effect.
- Guarantees **View Serializability** without aborting!
