// Link: https://leetcode.com/problems/split-array-largest-sum/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Maximum Subarray Sum)
// ==========================================
// Time Complexity  : O(n * log(sum - max))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper canSplit(maxSum):
     splits = 1, currentSum = 0
     For each x in nums:
         if currentSum + x > maxSum:
             splits++
             currentSum = 0
         currentSum += x
     return splits <= k
2. Search range:
     low = max(nums), high = sum(nums), ans = high.
3. While low <= high:
     mid = low + (high - low) / 2
     if canSplit(mid):
         ans = mid
         high = mid - 1 // Try smaller max sum
     else:
         low = mid + 1
4. Return ans.
*/

class Solution {
private:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int splits = 1;
        int currentSum = 0;

        for (int x : nums) {
            if (currentSum + x > maxSum) {
                splits++;
                currentSum = 0;
            }
            currentSum += x;
        }

        return splits <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for (int x : nums) high += x;

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
