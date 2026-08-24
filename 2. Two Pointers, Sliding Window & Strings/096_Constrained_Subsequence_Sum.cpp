// Link: https://leetcode.com/problems/constrained-subsequence-sum/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (DP + Monotonic Deque)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. dp[i] is max subsequence sum ending at index i.
2. dp[i] = nums[i] + max(0, max(dp[i-k..i-1])).
3. Maintain monotonic decreasing deque dq storing indices of maximum dp values in window of size k.
4. For i from 0 to n-1:
     Remove indices from dq front if i - dq.front() > k.
     dp[i] = nums[i] + (!dq.empty() ? max(0, dp[dq.front()]) : 0)
     ans = max(ans, dp[i])
     While !dq.empty() && dp[dq.back()] <= dp[i]:
         dq.pop_back()
     dq.push_back(i)
5. Return ans.
*/

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq; // Monotonic decreasing deque storing indices

        int ans = nums[0];

        for (int i = 0; i < n; i++) {
            // Remove indices outside window of size k
            if (!dq.empty() && i - dq.front() > k) {
                dq.pop_front();
            }

            // Max previous valid sum (at least 0)
            int maxPrev = (!dq.empty()) ? max(0, dp[dq.front()]) : 0;
            dp[i] = nums[i] + maxPrev;
            ans = max(ans, dp[i]);

            // Maintain decreasing order in deque
            while (!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return ans;
    }
};
