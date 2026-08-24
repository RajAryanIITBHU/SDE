# 8. Free Space Management in Operating Systems

To allocate disk blocks to files, the OS must maintain a list of all currently unallocated (free) blocks on disk.

---

## 4 Free Space Management Techniques

### 1. Bit Vector / Bitmap
- Uses an array of bits where each bit corresponds to one physical disk block:
  - `0` $\to$ Block is allocated / in-use.
  - `1` $\to$ Block is free.
- **Finding First Free Block:** Extremely fast using CPU word operations (`__builtin_ffs` / find first set bit).
- **Space Overhead:** Small (e.g., a 1 TB disk with 4 KB blocks needs only $32\text{ MB}$ for the bitmap).

---

### 2. Linked Free List
- Links all free disk blocks together using pointers inside the free blocks themselves.
- The OS only keeps a pointer to the **first free block** in the superblock.
- **Pros:** No extra space overhead (uses unused free blocks).
- **Cons:** Slow to traverse; cannot allocate contiguous chunks easily.

---

### 3. Grouping (Modified Linked List)
- Stores the addresses of $n$ free blocks in the first free block.
- The first $n - 1$ blocks are genuinely free; the $n$-th block contains the addresses of the next $n$ free blocks.
- **Advantage:** Allows quick batch retrieval of large numbers of free blocks.

---

### 4. Counting
- Takes advantage of the fact that multiple contiguous blocks are often allocated and freed simultaneously.
- Instead of keeping track of individual block addresses, store:
  $$\text{(Starting Free Block Number, Number of Contiguous Free Blocks)}$$
- e.g., `(Block 100, Length: 25)`.
- **Advantage:** Highly compact table, excellent for contiguous allocation.
