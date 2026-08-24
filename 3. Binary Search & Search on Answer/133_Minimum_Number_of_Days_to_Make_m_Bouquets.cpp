// Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Days)
// ==========================================
// Time Complexity  : O(n * log(max(bloomDay)))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If (long long)m * k > bloomDay.size() return -1 (not enough flowers).
2. Helper canMake(day):
     bouquets = 0, consecutive = 0
     For each b in bloomDay:
         if b <= day:
             consecutive++
             if consecutive == k:
                 bouquets++
                 consecutive = 0
         else:
             consecutive = 0
     return bouquets >= m
3. low = min(bloomDay), high = max(bloomDay), ans = high.
4. While low <= high:
     mid = low + (high - low) / 2
     if canMake(mid):
         ans = mid
         high = mid - 1
     else:
         low = mid + 1
5. Return ans.
*/

class Solution {
private:
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int consecutive = 0;

        for (int b : bloomDay) {
            if (b <= day) {
                consecutive++;
                if (consecutive == k) {
                    bouquets++;
                    consecutive = 0;
                }
            } else {
                consecutive = 0;
            }
        }

        return bouquets >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > (long long)bloomDay.size()) {
            return -1;
        }

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1; // Try earlier day
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
