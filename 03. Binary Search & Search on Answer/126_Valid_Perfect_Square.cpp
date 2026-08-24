// Link: https://leetcode.com/problems/valid-perfect-square/

#include <iostream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search)
// ==========================================
// Time Complexity  : O(log num)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If num == 1 return true.
2. low = 1, high = num / 2.
3. While low <= high:
     mid = low + (high - low) / 2
     sq = (long long)mid * mid
     if sq == num -> return true
     else if sq < num -> low = mid + 1
     else -> high = mid - 1
4. Return false.
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;

        int low = 1;
        int high = num / 2;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long sq = mid * mid;

            if (sq == num) {
                return true;
            } else if (sq < num) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};
