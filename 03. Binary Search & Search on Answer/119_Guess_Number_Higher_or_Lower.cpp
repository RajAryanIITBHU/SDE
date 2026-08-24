// Link: https://leetcode.com/problems/guess-number-higher-or-lower/

#include <iostream>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if num is higher than the picked number
//          1 if num is lower than the picked number
//          otherwise return 0
int guess(int num);

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search)
// ==========================================
// Time Complexity  : O(log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize low = 1, high = n.
2. While low <= high:
     mid = low + (high - low) / 2
     res = guess(mid)
     if res == 0 -> return mid
     else if res == -1 -> high = mid - 1 (picked number is lower)
     else -> low = mid + 1 (picked number is higher)
3. Return -1.
*/

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int res = guess(mid);

            if (res == 0) {
                return mid; // Correct guess
            } else if (res == -1) {
                high = mid - 1; // My guess is higher than the picked number
            } else {
                low = mid + 1; // My guess is lower than the picked number
            }
        }

        return -1;
    }
};
