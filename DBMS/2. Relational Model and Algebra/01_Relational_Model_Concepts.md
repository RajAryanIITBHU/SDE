# 1. Relational Model Concepts

## What is the Relational Model?
Introduced by E.F. Codd in 1970, the **Relational Model** represents data as a collection of two-dimensional tables called **Relations**.

---

## Core Terminology & Formal Mathematical Definitions

```
                     STUDENT RELATION (TABLE)
 +------------+--------------+-----------+-------------+
 |  Roll_No   |     Name     |    Age    |   Branch    |  <-- Attributes (Columns)
 +------------+--------------+-----------+-------------+
 |    101     |    Alice     |    20     |     CSE     |  <-- Tuple (Row / Record)
 |    102     |     Bob      |    21     |     ECE     |  <-- Tuple
 |    103     |   Charlie    |    19     |     CSE     |  <-- Tuple
 +------------+--------------+-----------+-------------+
```

| Relational Term | Formal Mathematical Term | Common DBMS Term |
| :--- | :--- | :--- |
| **Relation** | Set of Tuples | Table |
| **Tuple** | Ordered collection of attribute values | Row / Record |
| **Attribute** | Named column of a relation | Column / Field |
| **Domain** | Set of allowable atomic values for an attribute | Data Type / Permitted Values |
| **Schema** | $R(A_1, A_2, \dots, A_n)$ (Structure definition) | Table Structure / DDL |
| **Instance / State**| The set of tuples at a specific moment in time | Current Table Data |

---

## Degree vs. Cardinality (High-Frequency Interview Question!)

$$\text{Degree of a Relation} = \text{Total Number of ATTRIBUTES (Columns)}$$

$$\text{Cardinality of a Relation} = \text{Total Number of TUPLES (Rows)}$$

### Example from the Student Table above:
- **Degree:** $4$ (Attributes: `Roll_No`, `Name`, `Age`, `Branch`).
- **Cardinality:** $3$ (3 student rows).

---

## Relational Integrity Constraints
1. **Domain Constraint:** Value in each attribute must be an atomic value from that attribute's domain.
2. **Entity Integrity Constraint:** No primary key attribute value can be `NULL`.
3. **Referential Integrity Constraint:** A foreign key must either refer to a valid existing primary key tuple in the referenced relation or be `NULL`.
4. **Key Constraint:** Every relation must have at least one candidate key that uniquely identifies each tuple.
