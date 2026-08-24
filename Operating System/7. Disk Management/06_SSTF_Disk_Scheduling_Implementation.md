# 6. SSTF (Shortest Seek Time First) Disk Scheduling Implementation

## C++ Code Implementation of SSTF

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

void calculateSSTF(const vector<int>& requests, int initialHead) {
    int n = requests.size();
    vector<bool> visited(n, false);
    vector<int> seekSequence;
    int totalHeadMovements = 0;
    int currentHead = initialHead;

    for (int i = 0; i < n; i++) {
        int minDistance = INT_MAX;
        int closestIndex = -1;

        // Find unvisited request with shortest seek distance from current head
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int distance = abs(requests[j] - currentHead);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestIndex = j;
                }
            }
        }

        visited[closestIndex] = true;
        totalHeadMovements += minDistance;
        currentHead = requests[closestIndex];
        seekSequence.push_back(currentHead);
    }

    cout << "Total Number of Head Movements (Seek Operations) = " << totalHeadMovements << endl;
    cout << "Seek Sequence: ";
    for (int track : seekSequence) {
        cout << track << " ";
    }
    cout << endl;
}

int main() {
    vector<int> requests = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;

    calculateSSTF(requests, head);
    return 0;
}
```

---

## Example Dry-Run:
- Initial Head: `50`
- Requests: `[176, 79, 34, 60, 92, 11, 41, 114]`
- Sequence: `50 -> 41 -> 34 -> 11 -> 60 -> 79 -> 92 -> 114 -> 176`
- Total Seek Distance: `204 tracks`.
