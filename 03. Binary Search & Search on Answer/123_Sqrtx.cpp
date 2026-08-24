// Link: https://leetcode.com/problems/sqrtx/

#include <iostream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Integer Square Root)
// ==========================================
// Time Complexity  : O(log x)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If x == 0 or x == 1 return x.
2. low = 1, high = x / 2, ans = 1.
3. While low <= high:
     mid = low + (high - low) / 2
     if (long long)mid * mid <= x:
         ans = mid
         low = mid + 1
     else:
         high = mid - 1
4. Return ans.
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int low = 1;
        int high = x / 2;
        int ans = 1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid * mid <= x) {
                ans = mid;
                low = mid + 1; // Try larger candidate
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
