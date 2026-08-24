# 1. Process Introduction & Memory Layout

## What is a Process?
- **Program:** A passive entity stored on disk (e.g., `a.out`, `chrome.exe`).
- **Process:** An **active entity**—a program in execution with its own allocated memory, program counter, and resources.

---

## Memory Layout of a Process in RAM

When a program is executed, the OS allocates a contiguous virtual address space divided into 4 main segments:

```
+------------------------------------+ High Memory Address (0xFFFFFFFF)
|               STACK                | -> Grows downward
|  (Local variables, Function args,  |
|   Return addresses, Stack frames)  |
+------------------------------------+
|                 |                  |
|                 v                  |
|                                    |
|                 ^                  |
|                 |                  |
+------------------------------------+
|                HEAP                | -> Grows upward
|  (Dynamically allocated memory:    |
|   malloc(), calloc(), new)         |
+------------------------------------+
|             DATA SEGMENT           |
|  - BSS (Uninitialized Globals/Statics)|
|  - Initialized Globals & Statics   |
+------------------------------------+
|             TEXT (CODE)            |
|  (Binary machine instructions,     |
|   read-only)                       |
+------------------------------------+ Low Memory Address (0x00000000)
```

---

## Segment Breakdown

| Segment | Content | Memory Growth Direction |
| :--- | :--- | :--- |
| **Stack** | Local variables, function calls, return addresses | Grows **downward** (High to Low) |
| **Heap** | Dynamic memory allocated at runtime via `malloc()` / `new` | Grows **upward** (Low to High) |
| **Data (BSS)** | Uninitialized global and static variables (zero-initialized) | Fixed size |
| **Data (Init)** | Initialized global and static variables (e.g., `int x = 10;`) | Fixed size |
| **Text / Code** | Executable binary instructions (Read-Only to prevent self-modification) | Fixed size |
