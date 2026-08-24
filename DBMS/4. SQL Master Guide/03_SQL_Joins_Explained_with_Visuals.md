# 3. SQL Joins Explained with Visual Diagrams

A **Join** clause combines rows from two or more tables based on a related column between them.

---

## Visual Comparison of SQL Joins

```
      INNER JOIN                    LEFT JOIN                     RIGHT JOIN
   +-------+-------+             +-------+-------+             +-------+-------+
  /         \     / \           / ******* \     / \           /         \ ***** \
 |     A     |***| B |         | *   A   *|***| B |         |     A     |***| B *|
  \         / *** \ /           \ ******* / *** \ /           \         / *** \ * /
   +-------+-------+             +-------+-------+             +-------+-------+
    Matching only                 All Left + Match              All Right + Match

================================================================================

      FULL OUTER JOIN                                  SELF JOIN
   +-------+-------+                         +---------------------------+
  / ******* \ *** / \                        | Table A joins with itself |
 | *   A   *|***|* B *|                      | (e.g. Employee -> Manager)|
  \ ******* / *** \ * /                      +---------------------------+
   +-------+-------+
    Everything from both
```

---

## 1. `INNER JOIN`
Returns only records that have **matching values in both tables**.

```sql
SELECT e.name, d.department_name
FROM Employees e
INNER JOIN Departments d ON e.department_id = d.id;
```

---

## 2. `LEFT OUTER JOIN` (or `LEFT JOIN`)
Returns **all records from the left table**, along with matched records from the right table. Non-matching right columns fill with `NULL`.

```sql
-- Find all employees and their department (including employees with no department assigned)
SELECT e.name, d.department_name
FROM Employees e
LEFT JOIN Departments d ON e.department_id = d.id;
```

---

## 3. `RIGHT OUTER JOIN` (or `RIGHT JOIN`)
Returns **all records from the right table**, and matching records from the left table.

```sql
-- Find all departments, including departments that currently have 0 employees
SELECT e.name, d.department_name
FROM Employees e
RIGHT JOIN Departments d ON e.department_id = d.id;
```

---

## 4. `FULL OUTER JOIN`
Returns **all records when there is a match in either left or right table**.

```sql
SELECT e.name, d.department_name
FROM Employees e
FULL OUTER JOIN Departments d ON e.department_id = d.id;
```

---

## 5. `SELF JOIN` (Classic Manager-Employee Hierarchy)
A table is joined with itself using table aliases.

```sql
-- Find each employee and their direct manager's name
SELECT 
    e.name AS Employee_Name, 
    m.name AS Manager_Name
FROM Employees e
LEFT JOIN Employees m ON e.manager_id = m.employee_id;
```

---

## 6. `CROSS JOIN`
Computes the **Cartesian Product** of two tables (every row of Table A matched with every row of Table B).
