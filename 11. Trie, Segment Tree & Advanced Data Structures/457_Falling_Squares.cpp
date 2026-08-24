// Link: https://leetcode.com/problems/falling-squares/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Interval Height Simulation)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain list of placed squares: intervals of {left, right, height}.
2. maxHeight = 0, vector<int> ans.
3. For each square [left, side]:
     right = left + side
     baseHeight = 0
     For each placed square [pLeft, pRight, pHeight]:
         if max(left, pLeft) < min(right, pRight): // Overlapping interval
             baseHeight = max(baseHeight, pHeight)
     currHeight = baseHeight + side
     placed.push_back({left, right, currHeight})
     maxHeight = max(maxHeight, currHeight)
     ans.push_back(maxHeight)
4. Return ans.
*/

class Solution {
private:
    struct Interval {
        int left;
        int right;
        int height;
    };

public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<Interval> intervals;
        vector<int> ans;
        int maxHeight = 0;

        for (const auto& pos : positions) {
            int left = pos[0];
            int side = pos[1];
            int right = left + side;

            int baseHeight = 0;
            for (const auto& iv : intervals) {
                // Check if current dropping square overlaps horizontally with placed square
                if (max(left, iv.left) < min(right, iv.right)) {
                    baseHeight = max(baseHeight, iv.height);
                }
            }

            int currHeight = baseHeight + side;
            intervals.push_back({left, right, currHeight});
            maxHeight = max(maxHeight, currHeight);

            ans.push_back(maxHeight);
        }

        return ans;
    }
};
