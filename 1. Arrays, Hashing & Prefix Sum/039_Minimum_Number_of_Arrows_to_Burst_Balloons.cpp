// Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy on End Coordinates)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If points is empty, return 0.
2. Sort points based on end coordinate points[i][1].
3. arrows = 1, lastArrowPos = points[0][1].
4. For i from 1 to n-1:
     if points[i][0] > lastArrowPos:
         arrows++ // Current balloon starts after last arrow position -> need new arrow
         lastArrowPos = points[i][1]
5. Return arrows.
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return 0;

        // Sort by end coordinate
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int lastArrowPos = points[0][1];

        for (int i = 1; i < n; i++) {
            // Balloon starts beyond current arrow reach
            if (points[i][0] > lastArrowPos) {
                arrows++;
                lastArrowPos = points[i][1];
            }
        }

        return arrows;
    }
};
