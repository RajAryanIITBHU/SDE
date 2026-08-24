# 3. Critical Section Problem & Synchronization Criteria

## What is a Critical Section?
A **Critical Section** is a code segment in a program where **shared resources** (shared variables, files, tables) are accessed and modified.

```cpp
do {
    // 1. Entry Section: Request permission to enter
    critical_section(); // 2. Critical Section: Shared resource access
    // 3. Exit Section: Release lock / notify others
    remainder_section(); // 4. Remainder Section: Non-shared code
} while (true);
```

---

## 3 Mandatory Criteria for Any Valid Solution

Any valid solution to the Critical Section problem **MUST satisfy all three criteria**:

```
+-----------------------------------------------------------+
| 1. Mutual Exclusion  | Only ONE process in CS at a time   | (Mandatory)
+-----------------------------------------------------------+
| 2. Progress          | Selection not blocked by others    | (Mandatory)
+-----------------------------------------------------------+
| 3. Bounded Waiting   | Bound on waiting turns to avoid    | (Mandatory)
|                      | starvation                         |
+-----------------------------------------------------------+
```

### 1. Mutual Exclusion (Safety Condition)
- If process $P_i$ is executing in its critical section, then **no other processes can be executing in their critical sections** simultaneously.

### 2. Progress (Liveness Condition)
- If no process is in its critical section and some processes wish to enter, only those processes that are **not in their remainder section** can participate in deciding who enters next.
- This decision **cannot be postponed indefinitely** (no deadlock).

### 3. Bounded Waiting (Starvation Avoidance)
- There must be a **limit/bound** on the number of times other processes are allowed to enter their critical sections after a process has made a request to enter and before that request is granted.
- Guarantees **no process starves indefinitely**.

---

*(Optional 4th Condition: **Architectural Neutrality / Hardware Independence** - No assumptions about CPU speed or processor count).*
