// Link: https://leetcode.com/problems/merge-intervals/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Nested Checking)
// ==========================================
// Time Complexity  : O(n log n) + O(n^2) in worst case
// Space Complexity : O(n) auxiliary space for visited/result
/*
PSEUDOCODE:
1. Sort intervals based on starting times.
2. Initialize vector<vector<int>> ans.
3. For i from 0 to n-1:
     start = intervals[i][0]
     end = intervals[i][1]
     if intervals[i] is already covered in ans -> continue
     For j from i+1 to n-1:
         if intervals[j][0] <= end:
             end = max(end, intervals[j][1])
         else:
             break
     ans.push_back({start, end})
4. Return ans.
*/

class SolutionBruteForce {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // If current interval is already covered by the last merged interval
            if (!ans.empty() && ans.back()[1] >= end) {
                continue;
            }

            // Check all next overlapping intervals
            for (int j = i + 1; j < n; j++) {
                if (intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                } else {
                    break;
                }
            }

            ans.push_back({start, end});
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Sorting + Single Pass Linear Merge)
// ==========================================
// Time Complexity  : O(n log n) for sorting
// Space Complexity : O(1) auxiliary space (excluding output array)
/*
PSEUDOCODE:
1. Sort intervals by start time: sort(intervals.begin(), intervals.end()).
2. Initialize vector<vector<int>> ans.
3. Iterate through each interval in intervals:
     a. If ans is empty OR current interval start > ans.back()[1] (no overlap):
          ans.push_back(interval)
     b. Else (overlap occurs):
          ans.back()[1] = max(ans.back()[1], interval[1])
4. Return ans.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        // Step 1: Sort intervals by their start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // Step 2: Traverse through all intervals
        for (int i = 0; i < n; i++) {
            // Case 1: If ans is empty or there is no overlap
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            } 
            // Case 2: Overlapping intervals, merge with previous
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};
