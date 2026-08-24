// Link: https://leetcode.com/problems/burst-balloons/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Interval DP / Bottom-Up Matrix)
// ==========================================
// Time Complexity  : O(n^3)
// Space Complexity : O(n^2)
/*
PSEUDOCODE:
1. Pad nums with 1 at beginning and end: arr = [1, ...nums, 1].
2. Initialize dp matrix of size (n + 2) x (n + 2) with 0.
3. For len from 1 to n:
     For left from 1 to n - len + 1:
         right = left + len - 1
         For k from left to right (k is the LAST balloon burst in [left, right]):
             coins = arr[left - 1] * arr[k] * arr[right + 1]
             dp[left][right] = max(dp[left][right], dp[left][k - 1] + coins + dp[k + 1][right])
4. Return dp[1][n].
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 2, 1);
        for (int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 1; len <= n; len++) {
            for (int left = 1; left <= n - len + 1; left++) {
                int right = left + len - 1;

                // Pick balloon k to be burst last in range [left, right]
                for (int k = left; k <= right; k++) {
                    int coins = arr[left - 1] * arr[k] * arr[right + 1];
                    dp[left][right] = max(dp[left][right], dp[left][k - 1] + coins + dp[k + 1][right]);
                }
            }
        }

        return dp[1][n];
    }
};
