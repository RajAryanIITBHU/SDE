// Link: https://leetcode.com/problems/non-overlapping-intervals/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy on End Times)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Sort intervals based on their end times: intervals[i][1].
2. Initialize ans = 0 (count of removed intervals).
3. Initialize lastEnd = intervals[0][1].
4. For i from 1 to n-1:
     // If current interval starts before previous ends -> overlap!
     if intervals[i][0] < lastEnd:
         ans++ // remove current interval (it has a later end time)
     else:
         lastEnd = intervals[i][1] // no overlap, keep it
5. Return ans.
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return 0;

        // Custom comparator to sort by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int ans = 0;
        int lastEnd = intervals[0][1];

        for (int i = 1; i < n; i++) {
            // Overlapping interval detected
            if (intervals[i][0] < lastEnd) {
                ans++;
            } else {
                lastEnd = intervals[i][1];
            }
        }

        return ans;
    }
};
