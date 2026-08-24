# 2. Database Recovery: Write-Ahead Logging (WAL) & Checkpoints

## What is Database Recovery?
The **Recovery Management Module** guarantees **Atomicity** and **Durability** in the event of system crashes, power failures, or transaction aborts.

---

## 1. Write-Ahead Logging (WAL) Protocol (The Golden Rule!)

> **"Before any modified data block is written to disk, the corresponding log record describing the update MUST be flushed to non-volatile storage first."**

### Format of a Log Record:
- $\langle T_i, \text{START} \rangle$
- $\langle T_i, X, V_{\text{old}}, V_{\text{new}} \rangle$ — (Transaction $T_i$ modified item $X$ from Old value to New value).
- $\langle T_i, \text{COMMIT} \rangle$
- $\langle T_i, \text{ABORT} \rangle$

---

## 2. UNDO and REDO Operations

During crash recovery:

1. **`REDO` Operation:** If the log contains $\langle T_i, \text{START} \rangle$ **AND** $\langle T_i, \text{COMMIT} \rangle$, set item values to $V_{\text{new}}$ to ensure **Durability**.
2. **`UNDO` Operation:** If the log contains $\langle T_i, \text{START} \rangle$ **BUT NO $\langle T_i, \text{COMMIT} \rangle$**, restore item values back to $V_{\text{old}}$ to ensure **Atomicity**.

---

## 3. Checkpoints (Fuzzy Checkpointing)

### Why Checkpoints are Needed:
Without checkpoints, recovery after a crash requires scanning the entire database log from the very beginning of time (slow and impractical).

### What Happens at a Checkpoint:
1. All modified buffer pool pages currently in RAM are **flushed to physical disk**.
2. A $\langle \text{CHECKPOINT } \{T_1, T_2, \dots\} \rangle$ record is written to the log.
3. **During Crash Recovery:** The recovery system only scans backward to the most recent checkpoint, saving massive recovery time!
