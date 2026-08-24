// Link: https://leetcode.com/problems/largest-divisible-subset/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sorting + LIS-style DP with Parent Pointers)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Sort nums in ascending order.
2. Initialize dp array of size n with 1, parent array with -1.
3. maxLen = 1, maxIdx = 0.
4. For i from 1 to n-1:
     For j from 0 to i-1:
         if nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]:
             dp[i] = dp[j] + 1
             parent[i] = j
     if dp[i] > maxLen:
         maxLen = dp[i]
         maxIdx = i
5. Backtrack from maxIdx using parent pointers to reconstruct subset.
6. Return ans.
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        int maxLen = 1;
        int maxIdx = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }

        vector<int> ans;
        int curr = maxIdx;

        while (curr != -1) {
            ans.push_back(nums[curr]);
            curr = parent[curr];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
