# 5. Disk Scheduling Algorithms

Because mechanical **Seek Time** dominates disk access latency, the OS uses **Disk Scheduling Algorithms** to re-order pending I/O requests to **minimize total head movement**.

---

## 1. FCFS (First-Come, First-Served)
- **Rule:** Service requests in the exact order they arrive in the I/O queue.
- **Pros:** Completely fair; zero starvation.
- **Cons:** Wild oscillations of the disk arm across tracks; high average seek time.

---

## 2. SSTF (Shortest Seek Time First)
- **Rule:** Always service the request that is **closest to the current head position** (minimum seek distance).
- **Pros:** Significantly lower total seek time than FCFS.
- **Cons:** **Causes Starvation** for requests at the extreme outer or inner tracks if a stream of requests near current head position keeps arriving.

---

## 3. SCAN (The Elevator Algorithm)
- **Rule:** The disk arm starts at one end of the disk and moves toward the other end, servicing all requests along the path until it reaches the **very end (track 0 or track max)**. It then reverses direction and repeats.
- **Pros:** High throughput, uniform wait times, **no starvation**.

---

## 4. C-SCAN (Circular SCAN)
- **Rule:** The arm moves in one direction only (e.g., inside to outside), servicing requests. When it reaches the end, it immediately returns to the start of the disk **without servicing any requests on the return trip**.
- **Pros:** Provides more uniform waiting times than standard SCAN.

---

## 5. LOOK and C-LOOK (Practical Modern Versions)
- **Rule:** Exactly like SCAN and C-SCAN, but the arm **only goes as far as the last request in that direction**, rather than traveling all the way to the absolute disk boundary track!
- **LOOK:** Reverses direction immediately at the highest/lowest pending request.
- **C-LOOK:** Jumps back immediately to the lowest pending request.
- **Most widely used algorithm in real OS implementations.**
