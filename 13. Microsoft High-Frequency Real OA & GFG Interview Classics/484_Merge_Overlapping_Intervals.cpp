// Link: https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sorting + Linear Interval Merge)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(1) auxiliary
/*
PSEUDOCODE:
1. Sort intervals by start time in ascending order.
2. vector<vector<int>> ans = {intervals[0]}.
3. For i from 1 to n-1:
     if intervals[i][0] <= ans.back()[1]:
         ans.back()[1] = max(ans.back()[1], intervals[i][1])
     else:
         ans.push_back(intervals[i])
4. Return ans.
*/

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < (int)intervals.size(); i++) {
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
