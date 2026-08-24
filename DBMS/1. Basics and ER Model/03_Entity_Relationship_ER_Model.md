# 3. Entity-Relationship (ER) Model

## What is an ER Model?
The **Entity-Relationship (ER) Model** is a high-level conceptual data model developed by Peter Chen (1976) to visually represent the logical structure of a database using entities, attributes, and relationships.

---

## 1. Core ER Diagram Components & Symbols

```
+-------------------------------------------------------------+
|  SYMBOL                  |  ER COMPONENT                    |
+--------------------------+----------------------------------+
|  Rectangle [   ]         |  Entity Set                      |
|  Double Rectangle [[ ]]  |  Weak Entity Set                 |
|  Ellipse (   )           |  Attribute                       |
|  Underlined Ellipse (_)  |  Primary Key / Key Attribute     |
|  Dashed Ellipse (- -)    |  Derived Attribute               |
|  Double Ellipse ((   ))  |  Multi-valued Attribute          |
|  Diamond <   >           |  Relationship Set                |
|  Double Diamond <<   >>  |  Identifying Relationship Set    |
|  Double Line ===         |  Total Participation             |
+-------------------------------------------------------------+
```

---

## 2. Types of Attributes

| Attribute Type | Definition | Example |
| :--- | :--- | :--- |
| **Simple / Atomic** | Cannot be divided into smaller sub-parts. | `Age`, `Salary` |
| **Composite** | Can be subdivided into smaller meaningful components. | `Address` $\to$ (`Street`, `City`, `ZipCode`) |
| **Single-Valued** | Holds exactly one value for an entity instance. | `Aadhar_Number`, `SSN` |
| **Multi-Valued** | Can hold multiple values for a single entity. | `Phone_Numbers`, `Email_Addresses` |
| **Derived** | Computed dynamically from other stored attributes. | `Age` (computed from `DateOfBirth`) |
| **Key Attribute** | Uniquely identifies each entity in the entity set. | `Student_ID`, `Employee_ID` |

---

## 3. Cardinality Ratios (Mapping Constraints)
1. **One-to-One (1:1):** One entity in $A$ is associated with at most one entity in $B$ (e.g., `Citizen` $\leftrightarrow$ `Passport`).
2. **One-to-Many (1:N):** One entity in $A$ is associated with many entities in $B$ (e.g., `Department` $\leftrightarrow$ `Employees`).
3. **Many-to-Many (M:N):** Many entities in $A$ are associated with many entities in $B$ (e.g., `Students` $\leftrightarrow$ `Courses`).

---

## 4. Weak Entity Sets vs. Strong Entity Sets
- **Strong Entity Set:** Has a **Primary Key** that uniquely identifies its entities independently (e.g., `Employee(Emp_ID)`).
- **Weak Entity Set:** **Does not have a primary key of its own**. It depends on the existence of an **Identifying (Strong) Entity Set**.
- **Discriminator / Partial Key (Dashed underline):** An attribute that uniquely distinguishes entities within the same owner instance (e.g., `Dependent(Emp_ID, Dependent_Name)`).
- **Participation:** A weak entity set **always has Total Participation** in its identifying relationship.
