# 5. System Initialization and Booting Process

## What is Booting?
**Booting** is the sequence of operations that a computer executes from the moment power is switched on until the Operating System is loaded into RAM and ready for user interaction.

---

## 6-Stage Booting Sequence

```
1. Power On & POST (Power-On Self-Test)
       |
2. BIOS / UEFI Execution
       |
3. MBR / GPT (Master Boot Record reading)
       |
4. Bootloader Execution (GRUB / Windows Boot Manager)
       |
5. Kernel Loading & Initialization
       |
6. Init / Systemd Process (PID = 1) -> User Login Screen
```

---

## Detailed Step Breakdown

### Step 1: POST (Power-On Self-Test)
- Executed directly from ROM.
- Checks hardware health: RAM, Keyboard, Hard Drive, CPU registers.
- If an error is detected, beeps are emitted or an error code displays.

### Step 2: BIOS / UEFI
- **BIOS (Basic Input/Output System)** or modern **UEFI (Unified Extensible Firmware Interface)** discovers bootable devices (SSD, HDD, USB) based on the configured boot order.

### Step 3: MBR / GPT Reading
- Reads sector 0 of the bootable drive: **Master Boot Record (MBR)** (512 bytes).
- Contains the partition table and primary bootloader code.

### Step 4: Bootloader (e.g., GRUB / LILO)
- **GRUB (Grand Unified Bootloader)** displays OS choices (if dual-booting).
- Loads the OS Kernel image (`vmlinuz`) and initial RAM disk (`initrd` / `initramfs`) into main memory (RAM).

### Step 5: Kernel Initialization
- Kernel configures CPU registers, establishes virtual memory page tables, mounts the root filesystem (`/`), and initializes hardware drivers.

### Step 6: Starting `init` / `systemd` (PID = 1)
- The kernel spawns the **ancestor of all user processes**: `init` (or `systemd`).
- Starts background services (daemons: networking, logging, UI display manager).
- Renders the graphical login prompt.
