// Link: https://leetcode.com/problems/interval-list-intersections/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Two Pointers)
// ==========================================
// Time Complexity  : O(n + m), where n = firstList.size(), m = secondList.size()
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. Initialize pointers i = 0 (firstList), j = 0 (secondList), and vector ans.
2. While i < firstList.size() and j < secondList.size():
     start = max(firstList[i][0], secondList[j][0])
     end = min(firstList[i][1], secondList[j][1])
     if start <= end:
         ans.push_back({start, end}) // Valid overlap
     // Advance the pointer whose interval ends earlier
     if firstList[i][1] < secondList[j][1]:
         i++
     else:
         j++
3. Return ans.
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();

        vector<vector<int>> ans;
        int i = 0;
        int j = 0;

        while (i < n && j < m) {
            // Find overlapping boundaries
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);

            // If there is a valid intersection
            if (start <= end) {
                ans.push_back({start, end});
            }

            // Move pointer for the interval that finishes first
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }

        return ans;
    }
};
