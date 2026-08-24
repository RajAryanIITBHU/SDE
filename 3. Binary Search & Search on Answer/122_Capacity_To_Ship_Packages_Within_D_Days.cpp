// Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Answer Capacity)
// ==========================================
// Time Complexity  : O(n * log(sum(weights) - max(weights)))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper canShip(capacity):
     days = 1, currentLoad = 0
     For each w in weights:
         if currentLoad + w > capacity:
             days++
             currentLoad = 0
         currentLoad += w
     return days <= d
2. Search range:
     low = max(weights) (must be able to carry heaviest package)
     high = sum(weights) (carry all packages in 1 day)
3. While low <= high:
     mid = low + (high - low) / 2
     if canShip(mid):
         ans = mid
         high = mid - 1
     else:
         low = mid + 1
4. Return ans.
*/

class Solution {
private:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int dayCount = 1;
        int currentLoad = 0;

        for (int w : weights) {
            if (currentLoad + w > capacity) {
                dayCount++;
                currentLoad = 0;
            }
            currentLoad += w;
        }

        return dayCount <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for (int w : weights) high += w;

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                ans = mid;
                high = mid - 1; // Try smaller capacity
            } else {
                low = mid + 1; // Increase capacity
            }
        }

        return ans;
    }
};
