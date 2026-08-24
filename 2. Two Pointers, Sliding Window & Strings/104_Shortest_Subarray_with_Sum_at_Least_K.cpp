// Link: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Prefix Sums + Monotonic Deque)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Build prefix sum array PS of size n+1 (using long long to avoid overflow).
2. Maintain monotonic increasing deque dq storing prefix sum indices.
3. For i from 0 to n:
     // Check if current PS[i] - PS[dq.front()] >= k
     While !dq.empty() && PS[i] - PS[dq.front()] >= k:
         ans = min(ans, i - dq.front())
         dq.pop_front() // No future index can make a shorter subarray with this start
     // Maintain monotonic increasing order in dq
     While !dq.empty() && PS[i] <= PS[dq.back()]:
         dq.pop_back()
     dq.push_back(i)
4. Return ans == INT_MAX ? -1 : ans.
*/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> PS(n + 1, 0);

        for (int i = 0; i < n; i++) {
            PS[i + 1] = PS[i] + nums[i];
        }

        deque<int> dq; // Stores indices of prefix sums in increasing order
        int ans = INT_MAX;

        for (int i = 0; i <= n; i++) {
            // Find valid shortest subarrays
            while (!dq.empty() && PS[i] - PS[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            // Maintain increasing order of prefix sums
            while (!dq.empty() && PS[i] <= PS[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
