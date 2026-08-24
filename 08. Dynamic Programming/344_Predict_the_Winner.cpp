// Link: https://leetcode.com/problems/predict-the-winner/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Interval Minimax 1D DP)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize dp vector with nums (dp[i] = nums[i] for subarray of length 1).
2. For len from 2 to n:
     For i from 0 to n - len:
         j = i + len - 1
         dp[i] = max(nums[i] - dp[i + 1], nums[j] - dp[i])
3. Return dp[0] >= 0.
*/

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = nums;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i] = max(nums[i] - dp[i + 1], nums[j] - dp[i]);
            }
        }

        return dp[0] >= 0;
    }
};
