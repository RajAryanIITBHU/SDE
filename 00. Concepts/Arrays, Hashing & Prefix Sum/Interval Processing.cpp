/*
 * ============================================================================
 * Concept: Interval Processing & Scheduling
 * Subtopic: Arrays, Hashing & Prefix Sum
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Interval problems involve merging overlapping intervals, inserting new intervals, checking overlaps, or finding maximum concurrent intervals.
Key technique: Sort intervals by start time `interval[0]`.
Two intervals `[a, b]` and `[c, d]` overlap if `max(a, c) <= min(b, d)`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N log N) due to sorting, O(N) sweep line / priority queue.
 * - Space Complexity: O(N) for storing merged intervals or heap.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Merging overlapping ranges (Merge Intervals LC 56).
- Meeting Rooms II (Find minimum rooms needed / max overlapping intervals).
- Non-overlapping intervals (Greedy selection by end time).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Merge Intervals (LC 56).
2. Insert Interval (LC 57).
3. Meeting Rooms II (LC 253 - Min Heap or Chronological Sweep Line).
4. Minimum Number of Arrows to Burst Balloons (LC 452).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Merge Overlapping Intervals
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] <= merged.back()[1]) {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto res = mergeIntervals(intervals);
    cout << "Merged Count: " << res.size() << "\n";
    return 0;
}
