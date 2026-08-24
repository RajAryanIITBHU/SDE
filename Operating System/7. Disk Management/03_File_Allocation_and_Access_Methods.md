# 3. File Allocation & Access Methods

## 1. File Allocation Methods (How Files are Stored on Disk Blocks)

```
 CONTIGUOUS ALLOCATION        LINKED ALLOCATION (FAT)       INDEXED ALLOCATION
+---------------------+     +-------------------------+     +------------------+
| Start: 12, Len: 4   |     | Block 12 -> Block 17    |     | Index Block: 50  |
| [12][13][14][15]    |     |   -> Block 23 -> NIL    |     | [12, 17, 23, ..] |
+---------------------+     +-------------------------+     +------------------+
```

### A. Contiguous Allocation
- Each file occupies a set of **adjacent disk blocks**.
- **Pros:** Ultra-fast sequential and direct (random) access; minimal disk head movement.
- **Cons:** Suffers from **External Fragmentation**; difficult to grow file size dynamically.

### B. Linked Allocation
- File blocks are scattered across disk; each block contains a **pointer to the next block**.
- **Pros:** No external fragmentation; files can grow easily.
- **Cons:** **No direct / random access** (must follow pointers sequentially from the start); pointer space overhead; risk of corruption if a link breaks.
- **Variation: File Allocation Table (FAT):** Pointers are pulled into an in-memory table (FAT32).

### C. Indexed Allocation
- Each file has an **Index Block** containing an array of pointers to all its data blocks.
- **Pros:** Supports fast direct access without external fragmentation.
- **Cons:** Index block overhead for small files.

---

## 2. File Access Methods

1. **Sequential Access:** Information in the file is processed in order, one record after the other (e.g., Audio/Video streaming, Compilers).
2. **Direct / Random Access:** Programs can jump directly to any block / byte using `seek()` (e.g., Databases).
3. **Indexed Access:** Uses an index built on top of the file to quickly locate records.
