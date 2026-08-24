# 4. Schedule Recoverability: Recoverable, Cascadeless & Strict

If a transaction fails or aborts mid-execution, the schedule must be **Recoverable** to prevent permanent data corruption.

---

## 1. Recoverable Schedule
- **Rule:** If transaction $T_j$ reads a data item previously written by $T_i$ ($W_i(X) \to R_j(X)$), then **$T_i$ MUST COMMIT BEFORE $T_j$ commits** ($C_i < C_j$).
- **Why?** If $T_j$ commits first and then $T_i$ aborts, the database cannot rollback $T_j$ (violating Durability).

---

## 2. Cascadeless Schedule (Avoids Cascading Aborts)
- **Cascading Rollback:** If $T_1$ aborts, causing $T_2$ to abort, which causes $T_3$ to abort...
- **Cascadeless Rule:** A transaction $T_j$ is only allowed to **READ** a data item $X$ **AFTER the transaction $T_i$ that modified $X$ has already COMMITTED** ($W_i(X) \to C_i \to R_j(X)$).

---

## 3. Strict Schedule
- **Strict Rule:** A transaction $T_j$ can **NEITHER READ NOR WRITE** a data item $X$ until the previous transaction $T_i$ that modified $X$ has **COMMITTED or ABORTED**.
- **Advantage:** Rollback of an aborted transaction is trivial (simply restore the pre-image value of the data item without affecting any other transactions).

---

## Hierarchy of Schedules

$$\text{Strict Schedules} \subset \text{Cascadeless Schedules} \subset \text{Recoverable Schedules}$$

```
+-------------------------------------------------------------+
|                     RECOVERABLE SCHEDULES                   |
|                                                             |
|       +---------------------------------------------+       |
|       |            CASCADELESS SCHEDULES            |       |
|       |                                             |       |
|       |       +-----------------------------+       |       |
|       |       |       STRICT SCHEDULES      |       |       |
|       |       +-----------------------------+       |       |
|       +---------------------------------------------+       |
+-------------------------------------------------------------+
```
