# 4. Secondary Storage (Hard Disk Drive Architecture & Performance Metrics)

## Physical Architecture of a Hard Disk Drive (HDD)

```
              +-----------------------------------------+
              |           Spindle (Rotates platters)    |
              +-----------------------------------------+
                                   |
           +===============================================+ Platter (Magnetic surface)
           |    [ Track (Concentric circle) ]              |
           |    [ Sector (e.g., 512 bytes / 4 KB) ]        |
           +===============================================+
                   ^
                   | Read/Write Head
             +-----------+
             | Actuator  | (Moves arm horizontally in and out across tracks)
             |    Arm    |
             +-----------+
```

### Components:
- **Platters:** Circular magnetic disks coated with magnetic recording material.
- **Tracks:** Concentric circular rings on the platter surface.
- **Sectors:** Smallest physical addressable unit on a track (typically 512 bytes or 4096 bytes).
- **Cylinder:** Set of all tracks at the exact same radius across all platters.
- **Read/Write Head:** Flies micro-inches above the magnetic surface.

---

## 3 Critical Disk Access Time Metrics

Total time to read or write a sector of data:

$$\text{Total Disk Access Time} = \text{Seek Time} + \text{Rotational Latency} + \text{Transfer Time}$$

### 1. Seek Time (Dominant Factor!)
- **Definition:** The time required for the mechanical actuator arm to physically position the read/write head over the desired **track / cylinder**.
- **Typical Value:** $3\text{ to }9\text{ milliseconds}$ (Slowest mechanical step).

### 2. Rotational Latency
- **Definition:** The time taken for the desired **sector** to rotate under the read/write head.
- **Average Rotational Latency:**
  $$\text{Average Latency} = \frac{1}{2 \times \text{Rotational Speed (RPM)}} \times 60\text{ seconds}$$
  *(For a 7200 RPM drive, Average Latency $\approx 4.16\text{ ms}$).*

### 3. Transfer Time
- **Definition:** The time required to physically transfer the bytes of data from disk magnetic surface to computer RAM.
  $$\text{Transfer Time} = \frac{\text{Data Size to Transfer}}{\text{Transfer Rate}}$$
