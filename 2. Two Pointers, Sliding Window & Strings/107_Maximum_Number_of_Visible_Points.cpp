// Link: https://leetcode.com/problems/maximum-number-of-visible-points/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Polar Angles + Sliding Window over 360 Degrees)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Count points at exact same location as observer (sameLoc).
2. For all other points, calculate angle theta = atan2(dy, dx) in degrees [0, 360).
3. Sort angles array.
4. Duplicate angles by adding 360 degrees to handle wrap-around: angles.push_back(angle + 360).
5. Sliding window [left, right]:
     While angles[right] - angles[left] > angle:
         left++
     maxVisible = max(maxVisible, right - left + 1)
6. Return maxVisible + sameLoc.
*/

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int sameLoc = 0;
        vector<double> angles;
        const double PI = acos(-1.0);

        for (auto& p : points) {
            int dx = p[0] - location[0];
            int dy = p[1] - location[1];

            if (dx == 0 && dy == 0) {
                sameLoc++;
            } else {
                double theta = atan2(dy, dx) * 180.0 / PI;
                if (theta < 0) theta += 360.0;
                angles.push_back(theta);
            }
        }

        sort(angles.begin(), angles.end());

        // Duplicate array with +360 degrees to cover circular wrapping
        int m = angles.size();
        for (int i = 0; i < m; i++) {
            angles.push_back(angles[i] + 360.0);
        }

        int maxVisible = 0;
        int left = 0;

        for (int right = 0; right < (int)angles.size(); right++) {
            while (angles[right] - angles[left] > angle) {
                left++;
            }
            maxVisible = max(maxVisible, right - left + 1);
        }

        return maxVisible + sameLoc;
    }
};
