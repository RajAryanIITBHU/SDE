# 4. Next Fit & Buddy System Memory Allocation

## 1. Next Fit Algorithm Implementation
Next Fit keeps a roving pointer to remember where the last allocation occurred, searching for the next suitable block circularly.

### C++ Code Implementation:
```cpp
#include <iostream>
#include <vector>

using namespace std;

void nextFit(int blockSize[], int m, int processSize[], int n) {
    vector<int> allocation(n, -1);
    int lastAllocatedIndex = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;
        // Search circularly through block list
        while (count < m) {
            if (blockSize[lastAllocatedIndex] >= processSize[i]) {
                allocation[i] = lastAllocatedIndex;
                blockSize[lastAllocatedIndex] -= processSize[i];
                break;
            }
            lastAllocatedIndex = (lastAllocatedIndex + 1) % m;
            count++;
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1) cout << allocation[i] + 1;
        else cout << "Not Allocated";
        cout << endl;
    }
}
```

---

## 2. The Buddy System (Power-of-2 Allocator)

The **Buddy System** is a memory allocation technique used in operating system kernels (e.g., Linux kernel) that splits memory into power-of-2 partitions ($2^k$).

### How Allocation Works:
1. When memory of size $S$ is requested, find smallest power-of-2 such that $2^k \ge S$.
2. If a free block of size $2^k$ is available, allocate it.
3. Otherwise, split a larger block of size $2^{k+1}$ into **two equal "buddies"** of size $2^k$. Repeat splitting until the desired size is reached.

### How Deallocation (Coalescing) Works:
- When a block is freed, the OS checks if its adjacent **buddy block** is also free.
- If both buddies are free, they are **coalesced (merged)** back into a single block of size $2^{k+1}$.

### Example:
```
Initial Free Memory: 1024 KB
Request 100 KB -> Needs 128 KB block.
1024 KB -> Split into [512 KB, 512 KB]
512 KB  -> Split into [256 KB, 256 KB]
256 KB  -> Split into [128 KB (Allocated), 128 KB (Free)]
```
- **Pros:** Fast allocation and instant $O(1)$ merging of adjacent buddies via bitwise XOR (`buddy_address = block_address ^ block_size`).
- **Cons:** Suffers from **Internal Fragmentation** (allocating 129 KB requires a 256 KB block).
