# 4. Lossless Join & Dependency Preserving Decomposition

When decomposing a large table $R$ into smaller tables $R_1, R_2, \dots, R_k$, the decomposition must satisfy two critical mathematical properties:

---

## 1. Lossless Join Decomposition (Non-Loss Decomposition)

### Definition:
A decomposition of $R$ into $R_1$ and $R_2$ is **Lossless** if taking the Natural Join ($\bowtie$) of $R_1$ and $R_2$ yields the **EXACT original relation $R$ without generating any spurious (fake) tuples**.

$$R_1 \bowtie R_2 = R$$

### Necessary and Sufficient Condition (3-Part Test):
A binary decomposition of $R$ into $R_1$ and $R_2$ is lossless **if and only if at least ONE of the following holds**:

$$1. \quad (R_1 \cap R_2) \to R_1 \quad \text{OR}$$
$$2. \quad (R_1 \cap R_2) \to R_2$$

*(In simple terms: The common attributes between $R_1$ and $R_2$ must form a **Candidate / Super Key of at least ONE of the decomposed relations**).*

---

## 2. Dependency Preserving Decomposition

### Definition:
A decomposition is **Dependency Preserving** if the union of functional dependencies in all decomposed sub-relations covers all the original functional dependencies:

$$(F_1 \cup F_2 \cup \dots \cup F_k)^+ = F^+$$

- **Why it matters:** Allows the database engine to enforce all business constraints locally within individual tables without executing expensive multi-table joins.

---

## BCNF vs. 3NF Trade-off (Top Interview Takeaway)

```
+-------------------------------------------------------------------+
|  3NF DECOMPOSITION  |  Guaranteed to be BOTH:                     |
|                     |  1. Lossless Join                           |
|                     |  2. Dependency Preserving                   |
+-------------------------------------------------------------------+
|  BCNF DECOMPOSITION |  Guaranteed to be Lossless Join, BUT        |
|                     |  MAY NOT ALWAYS BE Dependency Preserving!   |
+-------------------------------------------------------------------+
```
