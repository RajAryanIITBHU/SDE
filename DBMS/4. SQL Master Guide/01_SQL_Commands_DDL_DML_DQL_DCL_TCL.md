# 1. SQL Commands: DDL, DML, DQL, DCL & TCL

SQL (Structured Query Language) is categorized into 5 functional sublanguages:

```
                                  SQL COMMANDS
                                       |
    +-----------+-----------+----------+----------+-----------+
    |           |           |                     |           |
    v           v           v                     v           v
   DDL         DML         DQL                   DCL         TCL
 (Define)   (Manipulate)  (Query)              (Control)  (Transaction)
```

---

## 1. DDL (Data Definition Language)
Defines and alters database schema structures. DDL statements are **Auto-Committed** (cannot be rolled back).

- `CREATE`: Creates a new table, view, or index.
- `ALTER`: Modifies an existing database structure (add/drop columns).
- `DROP`: Deletes an entire table and its schema from disk permanently.
- `TRUNCATE`: Removes **all rows** from a table instantly while retaining schema structure (faster than `DELETE`, resets auto-increment IDs).
- `RENAME`: Renames a table or database object.

---

## 2. DML (Data Manipulation Language)
Modifies data stored inside tables. DML changes **can be committed or rolled back**.

- `INSERT`: Inserts new records into a table.
- `UPDATE`: Modifies existing column values based on a condition.
- `DELETE`: Removes specific records matching a `WHERE` condition.

---

## 3. DQL (Data Query Language)
- `SELECT`: Retrieves and projects data from one or more tables.

---

## 4. DCL (Data Control Language)
Manages user privileges and security permissions.

- `GRANT`: Gives permissions to users (e.g., `GRANT SELECT, INSERT ON Employees TO user1;`).
- `REVOKE`: Withdraws user permissions (e.g., `REVOKE INSERT ON Employees FROM user1;`).

---

## 5. TCL (Transaction Control Language)
Manages transactional consistency for DML operations.

- `COMMIT`: Saves all transactional changes permanently to disk.
- `ROLLBACK`: Reverts changes back to the start of the transaction or a savepoint.
- `SAVEPOINT`: Creates an intermediate marker within a transaction.

---

## High-Frequency Interview Question: `DELETE` vs. `TRUNCATE` vs. `DROP`

| Feature | `DELETE` | `TRUNCATE` | `DROP` |
| :--- | :--- | :--- | :--- |
| **Category** | DML | DDL | DDL |
| **`WHERE` Clause** | ✅ Yes (Filters rows) | ❌ No (Deletes all rows) | ❌ No |
| **Speed** | Slower (Logs row by row) | Very Fast (Deallocates pages) | Instant (Removes file) |
| **Rollback** | ✅ Yes (Within transaction) | ❌ No (Auto-committed) | ❌ No |
| **Schema State** | Retained | Retained | **Deleted completely** |
