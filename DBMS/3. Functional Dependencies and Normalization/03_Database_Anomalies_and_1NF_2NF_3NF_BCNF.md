# 3. Database Anomalies & Normal Forms (1NF, 2NF, 3NF, BCNF)

## What is Normalization?
**Normalization** is the systematic process of organizing data in a database to **eliminate data redundancy** and avoid undesirable **modification anomalies**.

---

## 3 Database Modification Anomalies
1. **Insertion Anomaly:** Unable to insert certain data without inserting other unrelated attributes (e.g., cannot add a new course unless at least one student enrolls).
2. **Deletion Anomaly:** Deleting one piece of data causes unintended loss of other critical data (e.g., deleting the only student enrolled in a course deletes the course itself).
3. **Update Anomaly:** Updating a value in one row leaves duplicate values in other rows outdated, creating data inconsistency.

---

## The Hierarchy of Normal Forms

```
      +-------------------------------------------------------+
      |  1NF: Atomic values only (No multi-valued attributes) |
      +-------------------------------------------------------+
                                  |
                                  v
      +-------------------------------------------------------+
      |  2NF: 1NF + NO PARTIAL DEPENDENCY                     |
      +-------------------------------------------------------+
                                  |
                                  v
      +-------------------------------------------------------+
      |  3NF: 2NF + NO TRANSITIVE DEPENDENCY                  |
      +-------------------------------------------------------+
                                  |
                                  v
      +-------------------------------------------------------+
      |  BCNF: Stricter 3NF (Determinant MUST be a Super Key) |
      +-------------------------------------------------------+
```

---

## Definitions & Prime/Non-Prime Terminology
- **Prime Attribute:** An attribute that is part of **ANY Candidate Key**.
- **Non-Prime Attribute:** An attribute that is **NOT part of ANY Candidate Key**.

---

## Detailed Rules for Each Normal Form

### 1. First Normal Form (1NF)
- Every column must contain only **Atomic (indivisible) values**.
- No repeating groups or multi-valued attributes (e.g., phone numbers must not be stored as a comma-separated string in a single cell).

### 2. Second Normal Form (2NF)
- Relation must be in **1NF**.
- **No Partial Dependency:** No non-prime attribute should be functionally dependent on a **proper subset of any candidate key**.
- *Rule Check:* If Candidate Key is a composite key $(A, B)$, you cannot have $A \to C$ where $C$ is non-prime.

### 3. Third Normal Form (3NF)
- Relation must be in **2NF**.
- **No Transitive Dependency:** No non-prime attribute should depend on another non-prime attribute.
- **Formal Definition:** For every non-trivial FD $X \to Y$, **EITHER:**
  1. $X$ is a **Super Key**, **OR**
  2. $Y$ is a **Prime Attribute**.

### 4. Boyce-Codd Normal Form (BCNF)
- Stricter version of 3NF (also called **3.5 NF**).
- **Formal Definition:** For every non-trivial FD $X \to Y$, **$X$ MUST BE A SUPER KEY**.
- (Removes the $Y \in \text{Prime}$ relaxation of 3NF).
