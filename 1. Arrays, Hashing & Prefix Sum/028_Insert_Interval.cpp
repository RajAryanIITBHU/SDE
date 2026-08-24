// Link: https://leetcode.com/problems/insert-interval/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Append, Sort & Merge)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Push newInterval into intervals.
2. Sort intervals by start time.
3. Merge overlapping intervals (same as LC 56).
4. Return merged list.
*/

class SolutionBruteForce {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Single Pass Linear 3-Stage Scan)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. Initialize ans.
2. Stage 1: Add all intervals ending before newInterval starts.
3. Stage 2: Merge overlapping intervals with newInterval (intervals starting before newInterval ends).
4. Add the merged newInterval.
5. Stage 3: Add all remaining intervals.
6. Return ans.
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;

        // Stage 1: Add all non-overlapping intervals coming before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Stage 2: Merge overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        // Stage 3: Add all remaining non-overlapping intervals
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};
