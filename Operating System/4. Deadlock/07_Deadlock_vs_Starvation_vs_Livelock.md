# 7. Deadlock vs. Starvation vs. Livelock

These three concepts represent distinct concurrency synchronization problems:

---

## 1. Deadlock
- **Definition:** Two or more processes are blocked permanently waiting for resources held by each other in a cyclic dependency.
- **Process State:** **Waiting / Blocked** (Sleeping; consuming zero CPU).
- **Resolution:** Can **never** resolve without external intervention (aborting a process or OS reboot).

---

## 2. Starvation (Indefinite Blocking)
- **Definition:** A runnable process is repeatedly bypassed in the scheduling queue because other higher-priority processes are continuously favored.
- **Process State:** **Ready** (Ready to run, but not scheduled).
- **Resolution:** Resolved using **Aging** (progressively increasing wait-time priority).

---

## 3. Livelock
- **Definition:** Two or more processes continuously change their internal state in response to each other, but **neither makes any forward progress**.
- **Analogy:** Two polite people meeting in a narrow hallway repeatedly stepping to the exact same side simultaneously to let the other pass.
- **Process State:** **Running** (Actively using CPU cycles, unlike deadlock).
- **Resolution:** Add randomized delays / exponential backoff (e.g., Ethernet CSMA/CD).

---

## Direct Comparison Table

| Feature | Deadlock | Starvation | Livelock |
| :--- | :--- | :--- | :--- |
| **Process State** | Blocked / Waiting | Ready | Running / Active |
| **CPU Utilization** | Zero (Processes sleep) | High by other processes | 100% (Wasted looping) |
| **Cyclic Dependency** | Mandatory (Circular wait) | Not required | Mutual state oscillation |
| **Recovery** | Process abort / Preemption | Aging technique | Randomized backoff |
| **Can resolve itself?** | No, never | Yes (if high priority load stops) | No, stuck in loop |
