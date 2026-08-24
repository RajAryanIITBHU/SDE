# 2. Keys in DBMS & Referential Integrity Constraints

## The Hierarchy of Keys

```
+-----------------------------------------------------------+
|                     SUPER KEYS (SK)                       |
|   (Any set of attributes that uniquely identifies a row)  |
|                                                           |
|       +-------------------------------------------+       |
|       |           CANDIDATE KEYS (CK)             |       |
|       |       (Minimal Super Keys with no         |       |
|       |        redundant attributes)              |       |
|       |                                           |       |
|       |   +-------------------+  +------------+   |       |
|       |   |    PRIMARY KEY    |  | ALTERNATE  |   |       |
|       |   | (Chosen 1 Key,    |  |    KEYS    |   |       |
|       |   |  NOT NULL)        |  | (Remaining |   |       |
|       |   |                   |  |  CKs)      |   |       |
|       |   +-------------------+  +------------+   |       |
|       +-------------------------------------------+       |
+-----------------------------------------------------------+
```

---

## 1. Super Key (SK)
- A set of one or more attributes that **uniquely identifies a tuple** in a relation.
- *May contain redundant/extra attributes* (e.g., `{Roll_No, Name}`, `{Roll_No, Email, Age}`).

## 2. Candidate Key (CK)
- A **Minimal Super Key** (a super key from which no attribute can be removed without losing uniqueness).
- A relation can have multiple candidate keys (e.g., `{Roll_No}`, `{Email}`, `{Aadhar_Number}`).

## 3. Primary Key (PK)
- The single candidate key **chosen by the DBA** to uniquely identify tuples in the table.
- **Rule:** **Must be UNIQUE and NOT NULL**.

## 4. Alternate Key (AK)
- All candidate keys that were **not chosen** as the Primary Key.

## 5. Composite Key
- A primary or candidate key composed of **two or more attributes combined together** (e.g., `{Student_ID, Course_ID}`).

## 6. Foreign Key (FK) & Referential Integrity
- An attribute in a table that references the **Primary Key of another (or same) table**.
- Ensures relationships between tables remain consistent.

---

## Foreign Key Cascading Actions

When a referenced row in the Parent table is deleted or updated (`ON DELETE` / `ON UPDATE`):

| Action | Behavior |
| :--- | :--- |
| **`ON DELETE CASCADE`** | Automatically deletes all matching child rows in the child table. |
| **`ON DELETE SET NULL`** | Sets foreign key values in child rows to `NULL`. |
| **`ON DELETE RESTRICT / NO ACTION`** | Rejects the delete operation on the parent row if any child rows reference it. |
| **`ON DELETE SET DEFAULT`** | Sets foreign key values in child rows to a predefined default value. |
