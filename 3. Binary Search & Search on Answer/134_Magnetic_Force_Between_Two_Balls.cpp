// Link: https://leetcode.com/problems/magnetic-force-between-two-balls/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Answer Distance)
// ==========================================
// Time Complexity  : O(n log n + n * log(max_pos - min_pos))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Sort position array.
2. Helper canPlace(dist):
     count = 1, lastPos = position[0]
     For i from 1 to n-1:
         if position[i] - lastPos >= dist:
             count++
             lastPos = position[i]
     return count >= m
3. low = 1, high = position[n-1] - position[0], ans = 1.
4. While low <= high:
     mid = low + (high - low) / 2
     if canPlace(mid):
         ans = mid
         low = mid + 1 // Try larger minimum force
     else:
         high = mid - 1
5. Return ans.
*/

class Solution {
private:
    bool canPlace(vector<int>& position, int m, int dist) {
        int count = 1;
        int lastPos = position[0];

        for (int i = 1; i < (int)position.size(); i++) {
            if (position[i] - lastPos >= dist) {
                count++;
                lastPos = position[i];
            }
        }

        return count >= m;
    }

public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 1;
        int high = position.back() - position.front();
        int ans = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlace(position, m, mid)) {
                ans = mid;
                low = mid + 1; // Maximize minimum distance
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
