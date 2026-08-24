/*
 * ============================================================================
 * Concept: Task & Event Scheduling
 * Subtopic: Greedy Algorithms, Heap & Priority Queue
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Schedules tasks with cooldowns or priority requirements.
Uses frequency counting and greedy placement of most frequent tasks first.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time complexity.
 * - Space Complexity: O(1) space (26 frequency array).
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Task Scheduler (LC 621).
- Reorganize String (LC 767).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Task Scheduler (LC 621).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int leastInterval(const vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    int maxFreq = 0, maxCount = 0;
    for (char t : tasks) {
        freq[t - 'A']++;
        maxFreq = max(maxFreq, freq[t - 'A']);
    }
    for (int f : freq) {
        if (f == maxFreq) maxCount++;
    }
    int emptySlots = (maxFreq - 1) * (n - (maxCount - 1));
    int availableTasks = tasks.size() - maxFreq * maxCount;
    int idles = max(0, emptySlots - availableTasks);
    return tasks.size() + idles;
}

int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << "Min Execution Time (n=2): " << leastInterval(tasks, 2) << "\n"; // 8
    return 0;
}
