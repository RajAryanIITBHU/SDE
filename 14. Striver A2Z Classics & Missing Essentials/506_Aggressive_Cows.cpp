// Link: https://www.geeksforgeeks.org/problems/aggressive-cows/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Answer Space / Distance)
// ==========================================
// Time Complexity  : O(n log n + n log(maxDist))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Sort stalls in ascending order.
2. low = 1, high = stalls[n-1] - stalls[0].
3. Helper canPlaceCows(dist, stalls, k):
     cowsPlaced = 1, lastPos = stalls[0]
     For i from 1 to n-1:
         if stalls[i] - lastPos >= dist:
             cowsPlaced++
             lastPos = stalls[i]
             if cowsPlaced == k return true
     return false
4. BS in [low, high]:
     mid = low + (high - low) / 2
     if canPlaceCows(mid): ans = mid, low = mid + 1
     else: high = mid - 1
5. Return ans.
*/

class Solution {
private:
    bool canPlaceCows(int dist, const vector<int>& stalls, int k) {
        int count = 1;
        int lastPos = stalls[0];

        for (int i = 1; i < (int)stalls.size(); i++) {
            if (stalls[i] - lastPos >= dist) {
                count++;
                lastPos = stalls[i];
                if (count == k) return true;
            }
        }

        return false;
    }

public:
    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int n = stalls.size();
        int low = 1;
        int high = stalls[n - 1] - stalls[0];
        int ans = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlaceCows(mid, stalls, k)) {
                ans = mid;
                low = mid + 1; // Try to maximize minimum distance
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
