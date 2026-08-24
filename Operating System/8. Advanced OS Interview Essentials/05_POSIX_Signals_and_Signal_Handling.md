# 5. POSIX Signals & Signal Handling

## What is a Signal?
A **Signal** is an asynchronous software notification (software interrupt) sent by the OS kernel to a process to notify it that a specific event has occurred.

---

## High-Frequency Standard POSIX Signals

| Signal Name | Number | Default Action | Can be Caught / Blocked? | Trigger / Meaning |
| :--- | :---: | :--- | :---: | :--- |
| **`SIGINT`** | 2 | Terminate | ✅ Yes | Generated when user presses `Ctrl + C` in terminal. |
| **`SIGKILL`** | 9 | **Force Kill** | ❌ **NO (Uncatchable)** | Forcibly terminates process immediately by kernel. |
| **`SIGTERM`** | 15 | Graceful Exit | ✅ Yes | Polite request to terminate (allows cleanup). |
| **`SIGSEGV`** | 11 | Core Dump | ✅ Yes | **Segmentation Fault** (Invalid memory dereference). |
| **`SIGFPE`** | 8 | Core Dump | ✅ Yes | **Floating Point Exception** (Division by zero). |
| **`SIGCHLD`** | 17 | Ignore | ✅ Yes | Sent to parent when child process terminates/stops. |
| **`SIGSTOP`** | 19 | Suspend | ❌ **NO (Uncatchable)** | Pauses process execution (`Ctrl + Z`). |

---

## Signal Handling Code Example in C

```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Custom Signal Handler for SIGINT (Ctrl + C)
void handle_sigint(int sig) {
    printf("\nCaught SIGINT (%d)! Cleaning up resources before exit...\n", sig);
    exit(0);
}

int main() {
    // Register custom signal handler
    signal(SIGINT, handle_sigint);

    printf("Process running (PID: %d). Press Ctrl + C to test...\n", getpid());
    while (1) {
        sleep(1);
    }
    return 0;
}
```
