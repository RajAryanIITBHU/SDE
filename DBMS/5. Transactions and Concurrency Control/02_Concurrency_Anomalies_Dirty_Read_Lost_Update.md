# 2. Concurrency Anomalies & SQL Transaction Isolation Levels

When multiple transactions execute concurrently without adequate isolation, four classical anomalies occur:

---

## 4 Concurrency Anomalies

### 1. Dirty Read (Write-Read / WR Conflict)
- **Scenario:** Transaction $T_1$ modifies a row ($X = 100 \to 500$), but does not commit yet. Transaction $T_2$ reads $X = 500$. Then, $T_1$ **aborts and rolls back** to 100.
- **Problem:** $T_2$ executed logic based on "dirty" uncommitted data that never existed!

### 2. Unrepeatable Read (Read-Write / RW Conflict)
- **Scenario:** Transaction $T_1$ reads a row ($X = 100$). Concurrently, $T_2$ updates $X = 200$ and commits. $T_1$ reads the exact same row again and sees $X = 200$.
- **Problem:** Two consecutive reads within the same transaction return different values for the same row.

### 3. Lost Update (Write-Write / WW Conflict)
- **Scenario:** $T_1$ and $T_2$ read $X = 100$ simultaneously. $T_1$ writes $X = 110$ and commits. Immediately after, $T_2$ writes $X = 120$ and commits.
- **Problem:** $T_2$'s write completely overwrote and wiped out $T_1$'s update without knowing it.

### 4. Phantom Read
- **Scenario:** $T_1$ queries all employees with `age > 30` (finds 10 rows). $T_2$ inserts a new employee with `age = 35` and commits. $T_1$ runs the range query again and now finds **11 rows**.
- **Problem:** New "phantom" rows appear inside the transaction range.

---

## The 4 ANSI SQL Transaction Isolation Levels

| Isolation Level | Dirty Read | Unrepeatable Read | Phantom Read |
| :--- | :---: | :---: | :---: |
| **`READ UNCOMMITTED`** (Lowest) | ❌ Allowed | ❌ Allowed | ❌ Allowed |
| **`READ COMMITTED`** (Default in Postgres/Oracle) | ✅ **Prevented** | ❌ Allowed | ❌ Allowed |
| **`REPEATABLE READ`** (Default in MySQL InnoDB) | ✅ **Prevented** | ✅ **Prevented** | ❌ Allowed |
| **`SERIALIZABLE`** (Highest / Slowest) | ✅ **Prevented** | ✅ **Prevented** | ✅ **Prevented** |
