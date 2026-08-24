# 3. Static & Dynamic (Extendible) Hashing

## 1. Static Hashing
- **Concept:** Uses a fixed hash function $h(k)$ mapping search keys to a fixed number of disk buckets $B$.
- **Problem: Bucket Overflow:** If more records map to a bucket than its capacity, collision chains (overflow linked lists) degrade search speed from $O(1)$ to $O(N)$.
- **Problem:** Fixed size cannot grow or shrink gracefully as the database scales.

---

## 2. Extendible Hashing (Dynamic Hashing)

Extendible Hashing grows and shrinks dynamically without degrading performance.

### Architecture Components:
1. **Directory:** An array of $2^d$ pointers to data buckets, where $d$ is the **Global Depth**.
2. **Data Buckets:** Storage pages holding records, each maintaining a **Local Depth ($d'$)**.

```
 Global Depth (d = 2)
  Directory (4 entries)               Data Buckets
+---------------------+             +--------------------+
|  00                 | ----------> | Bucket A (d' = 2)  |
+---------------------+             +--------------------+
|  01                 | ----------> | Bucket B (d' = 2)  |
+---------------------+             +--------------------+
|  10                 | -------\
+---------------------+         +-> | Bucket C (d' = 1)  |
|  11                 | -------/    +--------------------+
+---------------------+
```

---

## Overflow Resolution Rules in Extendible Hashing

When inserting into a full bucket with local depth $d'$:

- **Case 1: $d' < d$ (Local Depth is LESS than Global Depth):**
  1. Split the overflowing bucket into two new buckets.
  2. Increment local depth: $d' = d' + 1$.
  3. Rehash the records between the two buckets.
  4. **Directory size DOES NOT double!** Simply update directory pointers.

- **Case 2: $d' == d$ (Local Depth EQUALS Global Depth):**
  1. **DOUBLE THE DIRECTORY SIZE!** Increment global depth: $d = d + 1$.
  2. Split the overflowing bucket and increment its local depth: $d' = d' + 1$.
  3. Rehash and reassign directory pointers.
