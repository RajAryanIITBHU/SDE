# 1. Zombie vs. Orphan Processes (High-Frequency Interview Question)

## 1. What is a Zombie Process? (Defunct Process)

### Definition
A **Zombie Process** (marked as `<defunct>` in Linux `ps` command) is a process that has **completed execution** via `exit()`, but **still has an entry in the Process Table**.

```
+-------------------------------------------------------------+
| Parent Process (PID 100)                                    |
|   |                                                         |
|   +---> Spawns Child (PID 101)                              |
|           |                                                 |
|           |--- Executes & Exits (`exit(0)`)                 |
|           v                                                 |
|         Child is DEAD, but its exit status (0) and PCB      |
|         remain in the Process Table!                        |
|                                                             |
|   Parent is busy / sleeping and DOES NOT call `wait()`!     |
|   ===> Child PID 101 becomes a ZOMBIE PROCESS!              |
+-------------------------------------------------------------+
```

### Why does the OS keep Zombies in the Process Table?
- When a child exits, the OS needs to preserve the child's **Exit Status Code** (e.g., 0 for success, non-zero for error) so the parent can read it later.
- The entry is removed from the Process Table **only after the parent calls `wait()` or `waitpid()`** (known as **Reaping** the child).

### Why are Zombie Processes dangerous?
- Zombies do not consume CPU or RAM memory (their address space is freed).
- However, **each zombie occupies a Process ID (PID) and a slot in the Process Table**.
- If a buggy parent creates thousands of zombies without calling `wait()`, the system **runs out of available PIDs**, preventing any new processes from starting!

### C Code: How a Zombie Process is Created
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process: Sleeps for 60 seconds WITHOUT calling wait()
        printf("Parent (PID: %d) sleeping... Child (PID: %d) will become a Zombie.\n", getpid(), pid);
        sleep(60);
    } else if (pid == 0) {
        // Child process: Exits immediately
        printf("Child (PID: %d) exiting now!\n", getpid());
        exit(0);
    }
    return 0;
}
```

### How to Prevent / Kill Zombie Processes
1. **Parent should call `wait()` or `waitpid()`:** Reaps the child's exit status immediately.
2. **Handle `SIGCHLD` signal:** Set up an asynchronous signal handler that calls `waitpid(-1, NULL, WNOHANG)`.
3. **Kill the Parent Process:** You cannot kill a zombie with `kill -9 <zombie_pid>` (it is already dead!). Killing the parent turns the zombie into an **Orphan**, and `init` (PID 1) immediately adopts and reaps it.

---

## 2. What is an Orphan Process?

### Definition
An **Orphan Process** is a running child process whose **parent process terminates or crashes before the child finishes execution**.

```
+-------------------------------------------------------------+
| Parent Process (PID 100)  ------> CRASHES / EXITS           |
|                                                             |
| Child Process (PID 101)   ------> Still running! (Orphan)   |
|                                                             |
| OS Action: Adopted by `init` / `systemd` (PID 1)             |
| When Child finishes, PID 1 automatically reaps it!          |
+-------------------------------------------------------------+
```

### What happens to an Orphan Process?
- The Linux Kernel automatically re-parents the orphan process to the **`init` or `systemd` process (PID 1)**.
- `init` continuously calls `wait()`, so when the orphan child finally exits, **`init` reaps it instantly**.
- Therefore, **orphan processes do NOT accumulate as zombies**.

### C Code: How an Orphan Process is Created
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process: Exits immediately
        printf("Parent (PID: %d) exiting immediately...\n", getpid());
        exit(0);
    } else if (pid == 0) {
        // Child process: Sleeps for 10 seconds (outlives parent)
        printf("Child (PID: %d), original parent PID: %d\n", getpid(), getppid());
        sleep(5);
        // After parent died, check new parent PID
        printf("Child (PID: %d), new adopted parent PID: %d (init/systemd)\n", getpid(), getppid());
    }
    return 0;
}
```

---

## Comparison Table: Zombie vs. Orphan

| Feature | Zombie Process | Orphan Process |
| :--- | :--- | :--- |
| **State** | **Dead / Terminated** (`Z` state) | **Alive / Actively Running** (`S` or `R` state) |
| **Parent Status** | Parent is **Alive**, but not calling `wait()` | Parent is **Dead / Terminated** |
| **Resource Usage** | No CPU / RAM; occupies a **PID slot in Process Table** | Actively consumes CPU, RAM, and system resources |
| **Parent Process** | Original parent | Adopted by `init` / `systemd` (PID 1) |
| **Harm to System** | Can exhaust system Process IDs (Process Table saturation) | Harmless (reaped automatically by `init` when done) |
| **How to eliminate** | Kill the parent process (so `init` adopts and reaps it) | Let it complete normally or `kill -9 <child_pid>` |
