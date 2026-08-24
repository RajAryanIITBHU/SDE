# 1. Introduction to DBMS & 3-Tier Architecture

## What is a Database Management System (DBMS)?
A **Database Management System (DBMS)** is specialized software that enables users to create, define, maintain, query, and control access to a structured collection of data (Database).

---

## DBMS vs. File Processing System

| Feature | Traditional File System | Database Management System (DBMS) |
| :--- | :--- | :--- |
| **Data Redundancy** | High (Duplicate data scattered across files) | Minimal (Controlled redundancy via normalization) |
| **Data Inconsistency** | High (Updating one file leaves other files stale) | Low (Single central source of truth) |
| **Concurrency Control** | Absent or rudimentary (File locking) | Robust multi-user transactions via ACID protocols |
| **Data Isolation / Security**| Weak (Difficult to enforce role-based access) | Granular permissions (`GRANT` / `REVOKE`) |
| **Crash Recovery** | Manual / High risk of file corruption | Automated Log-Based Recovery (Write-Ahead Logging) |

---

## The Three-Schema (Three-Level) ANSI-SPARC Architecture

To separate user interaction from physical hardware details, a DBMS is structured into **3 abstraction levels**:

```
+----------------------------------------------------------------+
|  EXTERNAL LEVEL (View Level / User Views)                      |
|  - View 1 (HR View)       View 2 (Finance)      View 3 (Public)|
+----------------------------------------------------------------+
                               |
                   Logical Data Independence
                               |
                               v
+----------------------------------------------------------------+
|  CONCEPTUAL LEVEL (Logical Level)                              |
|  - Global schema definition, Entities, Attributes, Relational  |
|    tables, Primary/Foreign keys, Business constraints          |
+----------------------------------------------------------------+
                               |
                  Physical Data Independence
                               |
                               v
+----------------------------------------------------------------+
|  INTERNAL LEVEL (Physical Level)                               |
|  - How data is stored on disk blocks, B+ Tree indexes, data    |
|    compression, byte offsets, file organization                |
+----------------------------------------------------------------+
                               |
                               v
                    [ Physical Hard Disks / SSD ]
```

### 1. View / External Level (Highest)
- Describes what subsets of data are visible to specific end-users or applications (hides rest of the database for security).

### 2. Conceptual / Logical Level (Middle)
- Describes **WHAT** data is stored in the entire database and the **relationships** among the data. Designed by Database Administrators (DBAs).

### 3. Internal / Physical Level (Lowest)
- Describes **HOW** data is physically formatted, compressed, indexed, and stored on persistent storage drives.
