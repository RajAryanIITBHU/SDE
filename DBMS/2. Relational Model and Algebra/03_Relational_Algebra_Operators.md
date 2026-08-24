# 3. Relational Algebra Operators

## What is Relational Algebra?
**Relational Algebra** is a formal, theoretical **procedural query language** that takes one or two relations as input and produces a new relation as output.

---

## 1. Fundamental Operators

### A. Selection ($\sigma$) — Unary (Horizontal Filtering)
- Filters **tuples (rows)** that satisfy a specified predicate condition.
- **Syntax:** $\sigma_{\text{Condition}}(R)$
- **SQL Equivalent:** `SELECT * FROM R WHERE Condition;`
- *Example:* $\sigma_{\text{Age} > 20}(\text{Student})$

### B. Projection ($\pi$) — Unary (Vertical Filtering)
- Selects specified **attributes (columns)** and automatically **eliminates duplicate tuples**.
- **Syntax:** $\pi_{A_1, A_2, \dots, A_k}(R)$
- **SQL Equivalent:** `SELECT DISTINCT A1, A2 FROM R;`
- *Example:* $\pi_{\text{Name, Branch}}(\text{Student})$

### C. Cartesian Product / Cross Product ($\times$) — Binary
- Combines every tuple of $R$ with every tuple of $S$.
- **Degree:** $\text{Degree}(R \times S) = \text{Degree}(R) + \text{Degree}(S)$
- **Cardinality:** $\text{Cardinality}(R \times S) = |R| \times |S|$

### D. Set Union ($\cup$), Set Difference ($-$), Set Intersection ($\cap$)
- Relations must be **Union-Compatible** (same number of attributes with matching compatible domains).

---

## 2. Derived Join Operators

```
+-------------------------------------------------------------+
| JOIN OPERATOR              | SYMBOL  | DEFINITION           |
+----------------------------+---------+----------------------+
| Theta Join                 | R ⋈_θ S | σ_θ(R × S)           |
| Equi Join                  | R ⋈_= S | Theta join with '='  |
| Natural Join               | R ⋈ S   | Equi-join on common  |
|                            |         | attributes + dedupe  |
| Left Outer Join            | R ⟕ S   | Keeps all left rows  |
| Right Outer Join           | R ⟖ S   | Keeps all right rows |
| Full Outer Join            | R ⟗ S   | Keeps all rows       |
+-------------------------------------------------------------+
```

---

## 3. Division Operator ($R \div S$) (Classic Interview Operator!)

Used for queries involving the word **"ALL"** (e.g., *"Find students who enrolled in ALL CSE courses"*).

- Produces tuples from $R$ that are associated with **every single tuple** in $S$.
