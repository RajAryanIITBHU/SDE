# 5. Top Interview SQL Queries & Solutions

Here are the highest-frequency SQL query patterns asked in Microsoft, Amazon, and Google technical rounds:

---

## 1. Find the $N$-th Highest Salary (Top 1 Most Frequent SQL Problem!)

### Approach A: Using `DENSE_RANK()` Window Function (Modern & Preferred)
```sql
-- Find the 2nd Highest Salary
WITH RankedSalaries AS (
    SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) as rnk
    FROM Employees
)
SELECT DISTINCT salary
FROM RankedSalaries
WHERE rnk = 2;
```

### Approach B: Using `LIMIT` and `OFFSET` (MySQL / PostgreSQL)
```sql
-- For N-th highest: OFFSET = N - 1
SELECT DISTINCT salary
FROM Employees
ORDER BY salary DESC
LIMIT 1 OFFSET 1; -- 2nd Highest
```

### Approach C: Using Correlated Subquery (Universal ANSI SQL)
```sql
SELECT DISTINCT e1.salary
FROM Employees e1
WHERE 2 = (
    SELECT COUNT(DISTINCT e2.salary)
    FROM Employees e2
    WHERE e2.salary >= e1.salary
);
```

---

## 2. Delete Duplicate Records while Keeping the Lowest ID

```sql
-- Solution using SELF JOIN:
DELETE e1
FROM Employees e1
JOIN Employees e2 
  ON e1.email = e2.email 
 AND e1.id > e2.id;
```

---

## 3. Find Employees Earning More than Their Direct Managers

```sql
SELECT e.name AS Employee
FROM Employees e
JOIN Employees m ON e.manager_id = m.id
WHERE e.salary > m.salary;
```

---

## 4. Find Customers Who Never Placed an Order

```sql
-- Solution A: LEFT JOIN with NULL check
SELECT c.name
FROM Customers c
LEFT JOIN Orders o ON c.id = o.customer_id
WHERE o.id IS NULL;

-- Solution B: NOT EXISTS
SELECT c.name
FROM Customers c
WHERE NOT EXISTS (
    SELECT 1 FROM Orders o WHERE o.customer_id = c.id
);
```

---

## 5. Consecutive Logins / Active Streaks (3 or More Consecutive Days)

```sql
WITH NumberedLogins AS (
    SELECT 
        user_id, 
        login_date,
        ROW_NUMBER() OVER (PARTITION BY user_id ORDER BY login_date) as rn,
        DATE_SUB(login_date, INTERVAL ROW_NUMBER() OVER (PARTITION BY user_id ORDER BY login_date) DAY) as grp
    FROM UserLogins
)
SELECT user_id, COUNT(*) as consecutive_days
FROM NumberedLogins
GROUP BY user_id, grp
HAVING COUNT(*) >= 3;
```
