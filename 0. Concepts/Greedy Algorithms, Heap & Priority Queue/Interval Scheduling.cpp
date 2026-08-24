/*
 * ============================================================================
 * Concept: Greedy Interval Scheduling
 * Subtopic: Greedy Algorithms, Heap & Priority Queue
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Selects maximum number of mutually non-overlapping intervals.
Key Strategy: Sort intervals by END TIME `interval[1]`. Pick interval ending earliest, then skip overlapping intervals.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N log N) sorting time.
 * - Space Complexity: O(1) auxiliary space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Non-overlapping Intervals (LC 435).
- N Meetings in One Room.
- Activity Selection.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Non-overlapping Intervals (LC 435).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    // Sort by end time
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
        return a[1] < b[1];
    });

    int count = 0;
    int lastEnd = intervals[0][1];

    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < lastEnd) {
            count++; // remove interval
        } else {
            lastEnd = intervals[i][1];
        }
    }
    return count;
}

int main() {
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << "Min Erased Intervals: " << eraseOverlapIntervals(intervals) << "\n"; // 1
    return 0;
}
