# 2. B-Trees & B+ Trees (Database Storage Engine Core)

## Why Binary Search Trees (BST / AVL / Red-Black) Fail for Databases:
- Binary trees have a fan-out of only 2.
- For 100 million records, a BST height is $\approx 27$. Locating a record would require **27 mechanical disk seeks** ($\approx 270\text{ ms}$ — too slow!).
- **B-Trees & B+ Trees** are self-balancing **Multi-Way Search Trees** with a massive branching factor (e.g., $M = 100$ to $500$), keeping tree height to only **3 to 4 levels** ($O(\log_M N)$).

---

## 1. B-Tree Structure
- Data records (or record pointers) are stored in **both internal nodes and leaf nodes**.

```
                         [ 20 | 50 ]  <-- Keys + Record Pointers in Internal Node
                        /     |     \
                       /      |      \
             [ 5 | 10 ]   [ 30 | 40 ]  [ 60 | 70 ]
```

---

## 2. B+ Tree Structure (Standard for Database Storage Engines)

In a **B+ Tree**:
1. **Internal Nodes** store **ONLY search keys and child page pointers** (No record pointers! Allows huge branching factor / fan-out).
2. **ALL actual data records / pointers** are stored exclusively in the **Leaf Nodes**.
3. **All Leaf Nodes are connected as a DOUBLY LINKED LIST** at the bottom level.

```
                         [ 20 | 50 ]  <-- Search Keys Only (Routing)
                        /     |     \
                       /      |      \
             [ 10 | 15 ]  [ 30 | 40 ]  [ 60 | 80 ]
                  |           |            |
                  v           v            v
Leaf Nodes:   [ 10, 15 ] <-> [ 20, 30, 40, 50 ] <-> [ 60, 70, 80, 90 ]
              (Contains actual data rows + Doubly linked list for fast range scan)
```

---

## Why B+ Trees are Superior to B-Trees for Databases (Top Interview Question!)

| Feature | B-Tree | B+ Tree (Standard in MySQL / Postgres) |
| :--- | :--- | :--- |
| **Data Storage** | Data stored in both internal and leaf nodes | Data stored **exclusively in Leaf Nodes** |
| **Internal Node Capacity**| Lower fan-out (data takes space) | **Higher fan-out** (Internal nodes hold more keys $\to$ shorter tree height) |
| **Range Queries (`BETWEEN`)**| Slow (Requires tree traversal / in-order traversal) | **Ultra-Fast** (Simply find start key and traverse linked list horizontally!) |
| **Search Consistency** | Variable (Root is fast, leaf is slow) | Consistent (Every search path reaches the leaf level at depth $h$) |
