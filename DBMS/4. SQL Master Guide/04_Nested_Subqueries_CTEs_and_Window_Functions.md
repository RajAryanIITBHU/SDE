# 4. Nested Subqueries, CTEs & Window Functions

## 1. Nested & Correlated Subqueries

### Nested (Independent) Subquery:
The inner query executes **once**, and its result is passed to the outer query.

```sql
-- Find employees earning more than the overall average salary
SELECT name, salary
FROM Employees
WHERE salary > (SELECT AVG(salary) FROM Employees);
```

### Correlated Subquery:
The inner query executes **once for EVERY ROW evaluated by the outer query** (references outer table alias).

```sql
-- Find employees earning more than the average salary of their OWN department
SELECT e.name, e.salary, e.department_id
FROM Employees e
WHERE e.salary > (
    SELECT AVG(d.salary)
    FROM Employees d
    WHERE d.department_id = e.department_id
);
```

---

## 2. Common Table Expressions (CTEs - `WITH` Clause)
A **CTE** is a temporary named result set defined within the execution scope of a single `SELECT`, `INSERT`, `UPDATE`, or `DELETE` statement.

```sql
-- Calculate department total salaries using a readable CTE
WITH DeptSalarySummary AS (
    SELECT department_id, SUM(salary) AS total_payroll
    FROM Employees
    GROUP BY department_id
)
SELECT d.department_name, s.total_payroll
FROM Departments d
JOIN DeptSalarySummary s ON d.id = s.department_id
WHERE s.total_payroll > 1000000;
```

---

## 3. Window Functions (`OVER()`, `ROW_NUMBER()`, `RANK()`, `DENSE_RANK()`)

Window functions perform calculations across a set of table rows that are related to the current row, **without collapsing the rows** (unlike `GROUP BY`).

| Function | Behavior on Ties (e.g. Salaries: 100, 100, 80) | Sequence Example |
| :--- | :--- | :--- |
| **`ROW_NUMBER()`** | Assigns unique sequential integers (no ties). | 1, 2, 3 |
| **`RANK()`** | Assigns same rank to ties; **skips subsequent ranks**. | 1, 1, 3 |
| **`DENSE_RANK()`** | Assigns same rank to ties; **does NOT skip ranks**. | 1, 1, 2 |

### Example Query:
```sql
SELECT 
    name,
    department_id,
    salary,
    ROW_NUMBER() OVER(PARTITION BY department_id ORDER BY salary DESC) AS row_num,
    RANK() OVER(PARTITION BY department_id ORDER BY salary DESC) AS rnk,
    DENSE_RANK() OVER(PARTITION BY department_id ORDER BY salary DESC) AS dense_rnk
FROM Employees;
```
