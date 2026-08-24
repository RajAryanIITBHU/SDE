# 1. File Organization & Indexing Types

## What is an Index in DBMS?
An **Index** is an auxiliary search data structure (ordered file or tree) that minimizes the number of disk block I/O accesses needed to locate records.

---

## 1. Dense Index vs. Sparse Index

| Feature | Dense Index | Sparse Index |
| :--- | :--- | :--- |
| **Index Entries** | Has an index entry for **EVERY search key value** in the data file. | Has an index entry for only a **subset of records** (e.g., first record of each disk block). |
| **Index Size** | Large (Takes more RAM / disk space) | Small (Fits easily into main memory) |
| **Search Speed** | Fast direct lookup | Looks up block anchor, then linear scans inside the disk block |
| **Data File Requirement**| Can be used on sorted or unsorted files | **Data file MUST BE PHYSICALLY SORTED** |

---

## 2. Primary Index vs. Clustered Index vs. Secondary Index

```
+-----------------------------------------------------------------------------------+
| INDEX TYPE        | DATA FILE ORDERING? | SEARCH KEY TYPE?    | DENSE / SPARSE?   |
+-------------------+---------------------+---------------------+-------------------+
| Primary Index     | Ordered (Sorted)    | Primary Key (Unique)| Usually Sparse    |
| Clustered Index   | Ordered (Sorted)    | Non-Key (Duplicates)| Sparse            |
| Secondary Index   | Unordered / Ordered | Key or Non-Key      | Dense             |
+-----------------------------------------------------------------------------------+
```

### A. Primary Index
- Defined on an **ordered data file** where the search key is a **Candidate / Primary Key** (unique).

### B. Clustered Index
- Defined on an **ordered data file** where the search key is a **non-key field with duplicate values** (e.g., `Department_ID`).
- Physically reorders the table rows on disk to match the index order (hence, a table can have **only ONE clustered index**).

### C. Secondary Index (Non-Clustered Index)
- Built on top of a data file whose physical ordering is different from the index search key.
- Creates a pointer list to the actual data rows (a table can have **multiple secondary indexes**).
