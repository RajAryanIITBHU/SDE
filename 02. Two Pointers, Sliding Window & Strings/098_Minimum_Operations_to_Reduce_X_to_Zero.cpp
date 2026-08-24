// Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sliding Window: Longest Subarray Sum = Total - X)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Target subarray sum = target = totalSum - x.
2. If target < 0 return -1.
3. If target == 0 return n.
4. Find maximum length of subarray with sum == target:
     sum = 0, left = 0, maxLen = -1.
     For right from 0 to n-1:
         sum += nums[right]
         While sum > target and left <= right:
             sum -= nums[left]
             left++
         if sum == target:
             maxLen = max(maxLen, right - left + 1)
5. Return maxLen == -1 ? -1 : n - maxLen.
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = 0;

        for (int val : nums) {
            totalSum += val;
        }

        int target = totalSum - x;
        if (target < 0) return -1;
        if (target == 0) return n;

        int left = 0;
        int sum = 0;
        int maxLen = -1;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum > target && left <= right) {
                sum -= nums[left];
                left++;
            }

            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return (maxLen == -1) ? -1 : n - maxLen;
    }
};
