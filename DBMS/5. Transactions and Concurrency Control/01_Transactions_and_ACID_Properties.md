# 1. Transactions & ACID Properties

## What is a Transaction?
A **Transaction** is a single logical unit of work that contains one or more database operations (Read / Write). Either **all operations succeed**, or **none take effect**.

---

## The 4 ACID Properties (Core Interview Pillar!)

```
+-------------------------------------------------------------------+
|  A - ATOMICITY     | "All or Nothing" (Managed by Recovery Mgr)   |
+-------------------------------------------------------------------+
|  C - CONSISTENCY   | Database moves from one valid state to       |
|                    | another (Managed by Application / Schema)    |
+-------------------------------------------------------------------+
|  I - ISOLATION     | Concurrent transactions do not interfere     |
|                    | with each other (Managed by Concurrency Mgr) |
+-------------------------------------------------------------------+
|  D - DURABILITY    | Committed changes persist across power cuts  |
|                    | and crashes (Managed by Recovery / Logs)     |
+-------------------------------------------------------------------+
```

### 1. Atomicity (All or Nothing)
- Entire transaction completes successfully or gets rolled back completely.
- *Example:* Bank Transfer of \$500 from Account A to Account B:
  1. Deduct \$500 from A.
  2. *[System crashes here]*
  3. Add \$500 to B.
- *Atomicity guarantees:* \$500 is not deducted from A if the credit to B fails.

### 2. Consistency (Preserving Invariants)
- Total sum of balances ($A + B$) remains identical before and after the transaction.

### 3. Isolation
- Intermediate states of a transaction are hidden from other concurrent transactions.

### 4. Durability
- Once a transaction commits, its modifications are permanently recorded in non-volatile storage (WAL log / disk) and cannot be lost even if power fails immediately after.

---

## Transaction State Diagram

```
                +-----------------+
                |     ACTIVE      | (Executing Read / Write)
                +-----------------+
                  /             \
                 /               \
                v                 v
     +--------------------+     +-----------------+
     | PARTIALLY COMMITTED|     |     FAILED      |
     +--------------------+     +-----------------+
                |                        |
             Commit                   Rollback
                |                        |
                v                        v
     +--------------------+     +-----------------+
     |     COMMITTED      |     |    ABORTED      |
     +--------------------+     +-----------------+
                |                        |
                +----------->+<----------+
                             |
                             v
                     +-----------------+
                     |   TERMINATED    |
                     +-----------------+
```
