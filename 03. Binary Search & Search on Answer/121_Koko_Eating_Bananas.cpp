// Link: https://leetcode.com/problems/koko-eating-bananas/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Answer)
// ==========================================
// Time Complexity  : O(n * log(max(piles)))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper canFinish(speed):
     hours = 0
     For each pile in piles:
         hours += (pile + speed - 1) / speed // ceil(pile / speed)
     return hours <= h
2. Search range: low = 1, high = max(piles), ans = high.
3. While low <= high:
     mid = low + (high - low) / 2
     if canFinish(mid):
         ans = mid
         high = mid - 1 // Try smaller eating speed
     else:
         low = mid + 1
4. Return ans.
*/

class Solution {
private:
    bool canFinish(vector<int>& piles, int h, int speed) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + speed - 1) / speed; // Ceiling division
        }
        return hours <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canFinish(piles, h, mid)) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid speed
            } else {
                low = mid + 1; // Speed too slow, increase speed
            }
        }

        return ans;
    }
};
