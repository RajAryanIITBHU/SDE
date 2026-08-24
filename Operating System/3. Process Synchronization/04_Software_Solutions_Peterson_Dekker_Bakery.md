# 4. Software Solutions: Peterson's, Dekker's & Bakery Algorithms

Software solutions to the Critical Section problem do not require special hardware atomic instructions.

---

## 1. Peterson's Algorithm (For 2 Processes)
Peterson's Algorithm uses two shared variables:
- `bool flag[2]`: `flag[i] = true` means process $P_i$ wants to enter the Critical Section.
- `int turn`: Indicates whose turn it is to enter.

### Implementation for Process $P_i$ (and other process $P_j$):
```cpp
do {
    flag[i] = true;      // Process i is interested
    turn = j;            // Gives preference to the other process
    
    // Busy wait as long as the other process is interested and has the turn
    while (flag[j] && turn == j);

    // CRITICAL SECTION
    // ... access shared resource ...

    flag[i] = false;     // Exit section: Process i is no longer interested

    // REMAINDER SECTION
} while (true);
```

### Verification of Criteria:
- **Mutual Exclusion:** Satisfied (both processes cannot pass `while` simultaneously).
- **Progress:** Satisfied (if $P_j$ is not interested, `flag[j] == false`, so $P_i$ enters immediately).
- **Bounded Waiting:** Satisfied (a process enters after at most one turn of the other process).

---

## 2. Dekker's Algorithm
- The **first historically correct software algorithm** for mutual exclusion between 2 processes.
- Uses `turn` and `flag[2]` with an internal loop adjusting `flag` when yielding the turn.

---

## 3. Lamport's Bakery Algorithm (For $N$ Processes)
Designed for coordinating $N$ processes based on a bakery token queue model:
- Before entering the critical section, each process takes a **ticket number**.
- The process with the **lowest ticket number** enters the critical section first.
- Ties are broken by the process with the smaller Process ID (`PID`).

```cpp
// For Process i:
choosing[i] = true;
number[i] = 1 + max(number[0], number[1], ..., number[n-1]);
choosing[i] = false;

for (int j = 0; j < n; j++) {
    while (choosing[j]); // Wait if process j is currently picking a number
    while (number[j] != 0 && (number[j], j) < (number[i], i)); // Wait if j has higher priority
}

// CRITICAL SECTION
number[i] = 0; // Release ticket
```
