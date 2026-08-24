# 7. Hard Links vs. Soft (Symbolic) Links in Unix/Linux

## 1. What is a Hard Link? (`ln source.txt hardlink.txt`)
- A **Hard Link** is simply an **additional directory entry that points directly to the exact same Inode** as the original file.
- Both directory entries share the same Inode number, permissions, owner, and data blocks on disk.
- **Link Count:** Inode maintains a `link_count`. When you create a hard link, `link_count++`. When you delete a file, `link_count--`.
- **Data Deletion:** The actual file data is deleted from disk **ONLY when `link_count == 0`**.
- **Constraint:** Hard links **cannot cross different filesystems/partitions**, and cannot link directories (to prevent directory graph cycles).

---

## 2. What is a Soft Link / Symlink? (`ln -s source.txt symlink.txt`)
- A **Soft Link (Symbolic Link)** is a completely **new, independent file with its own unique Inode**.
- Its data block contains the **path string** pointing to the target file.
- **Dangling / Broken Link:** If the target original file is deleted or moved, the soft link still points to the non-existent path and breaks.
- **Flexibility:** Can link across **different filesystems and partitions**, and can link directories.

---

## Visual Comparison

```
 HARD LINK:
 Directory Entry "file1.txt" ----\
                                  +---> [ INODE 1024 ] ---> [ Data Blocks on Disk ]
 Directory Entry "hardlink.txt" -/      (link_count = 2)

========================================================================

 SOFT LINK (SYMLINK):
 Directory Entry "file1.txt"   ---------> [ INODE 1024 ] ---> [ Data Blocks on Disk ]
 Directory Entry "symlink.txt" ---------> [ INODE 2048 ] ---> [ Path: "/path/to/file1.txt" ]
```

---

## Comparison Summary Table

| Feature | Hard Link (`ln`) | Soft Link / Symlink (`ln -s`) |
| :--- | :--- | :--- |
| **Inode Number** | **Identical** to original file | **Different** (Unique new Inode) |
| **File Type** | Normal file | Special link file (`l`) |
| **Cross Filesystem?** | ❌ No (same partition only) | ✅ Yes (can cross partitions/drives) |
| **Link Directories?** | ❌ No (prevent infinite loops) | ✅ Yes |
| **If Original is Deleted** | **Data is intact!** Hard link still works | **Breaks!** Becomes a dangling link |
| **Size** | Same size as original data | Size = Number of characters in path string |
