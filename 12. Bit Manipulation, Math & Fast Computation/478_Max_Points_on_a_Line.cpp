// Link: https://leetcode.com/problems/max-points-on-a-line/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Slope Hash Map with GCD Normalization)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. If points.size() <= 2 return points.size().
2. maxPointsOnLine = 0.
3. For i from 0 to n-1:
     unordered_map<string, int> slopeFreq
     currentMax = 0
     For j from i + 1 to n-1:
         dx = points[j][0] - points[i][0]
         dy = points[j][1] - points[i][1]
         g = std::gcd(dx, dy)
         dx /= g, dy /= g
         if dx < 0 || (dx == 0 && dy < 0):
             dx = -dx, dy = -dy
         key = to_string(dy) + "/" + to_string(dx)
         slopeFreq[key]++
         currentMax = max(currentMax, slopeFreq[key])
     maxPointsOnLine = max(maxPointsOnLine, currentMax + 1) // +1 includes point i
4. Return maxPointsOnLine.
*/

class Solution {
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int maxPointsCount = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopeFreq;
            int localMax = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Normalize direction to maintain consistent string keys
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                string slopeKey = to_string(dy) + "/" + to_string(dx);
                slopeFreq[slopeKey]++;
                localMax = max(localMax, slopeFreq[slopeKey]);
            }

            maxPointsCount = max(maxPointsCount, localMax + 1);
        }

        return maxPointsCount;
    }
};
