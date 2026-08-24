// Link: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sliding Window + Two Monotonic Deques)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain maxDq (monotonic decreasing) and minDq (monotonic increasing).
2. Initialize left = 0, ans = 0.
3. For right from 0 to n-1:
     Add nums[right] to maxDq and minDq maintaining monotonic properties.
     While maxDq.front() - minDq.front() > limit:
         if maxDq.front() == nums[left] -> maxDq.pop_front()
         if minDq.front() == nums[left] -> minDq.pop_front()
         left++
     ans = max(ans, right - left + 1)
4. Return ans.
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> maxDq; // Decreasing deque (front has max)
        deque<int> minDq; // Increasing deque (front has min)

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            while (!maxDq.empty() && maxDq.back() < nums[right]) maxDq.pop_back();
            while (!minDq.empty() && minDq.back() > nums[right]) minDq.pop_back();

            maxDq.push_back(nums[right]);
            minDq.push_back(nums[right]);

            // Shrink window if difference exceeds limit
            while (maxDq.front() - minDq.front() > limit) {
                if (maxDq.front() == nums[left]) maxDq.pop_front();
                if (minDq.front() == nums[left]) minDq.pop_front();
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
