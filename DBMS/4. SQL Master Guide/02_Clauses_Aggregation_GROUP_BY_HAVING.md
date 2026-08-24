# 2. SQL Clauses, Aggregations & `WHERE` vs. `HAVING`

## Logical SQL Query Execution Order

Understanding the order in which the SQL query engine processes clauses is essential:

```
1. FROM / JOIN     -> Identify source tables and perform joins
2. WHERE           -> Filter individual base rows
3. GROUP BY        -> Group rows into aggregate buckets
4. HAVING          -> Filter aggregated groups
5. SELECT          -> Project requested columns / expressions
6. DISTINCT        -> Deduplicate projected rows
7. ORDER BY        -> Sort final output rows
8. LIMIT / OFFSET  -> Restrict number of returned rows
```

---

## 1. Aggregate Functions
Compute a single summary result from multiple input values:
- `COUNT(column)`: Counts non-null values (`COUNT(*)` counts all rows).
- `SUM(column)`: Sums numeric values.
- `AVG(column)`: Computes arithmetic mean.
- `MIN(column)` / `MAX(column)`: Finds minimum / maximum value.

---

## 2. `GROUP BY` and `HAVING` Example

```sql
-- Find departments with more than 5 employees having an average salary > $80,000
SELECT 
    department_id,
    COUNT(employee_id) AS total_employees,
    AVG(salary) AS avg_salary
FROM Employees
WHERE status = 'Active'               -- 1. Filters active individual rows
GROUP BY department_id                -- 2. Groups rows by department
HAVING COUNT(employee_id) > 5         -- 3. Filters departments with > 5 staff
   AND AVG(salary) > 80000            -- 4. Filters departments with avg salary > 80k
ORDER BY avg_salary DESC;             -- 5. Sorts results
```

---

## 3. `WHERE` vs. `HAVING` Comparison Table

| Feature | `WHERE` Clause | `HAVING` Clause |
| :--- | :--- | :--- |
| **Filtering Level** | Filters **individual rows** before grouping | Filters **aggregated groups** after grouping |
| **Position** | Executed **before** `GROUP BY` | Executed **after** `GROUP BY` |
| **Aggregate Functions** | ❌ Cannot contain aggregates (`WHERE SUM(salary) > 1000` is ILLEGAL) | ✅ Can contain aggregates (`HAVING AVG(salary) > 50000`) |
| **Usage without `GROUP BY`**| Normal usage | Rare (Treats whole table as one single group) |
