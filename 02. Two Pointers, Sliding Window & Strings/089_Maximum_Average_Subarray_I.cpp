// Link: https://leetcode.com/problems/maximum-average-subarray-i/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Fixed Sliding Window of Size K)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. sum = sum of first k elements.
2. maxSum = sum.
3. For i from k to n-1:
     sum += nums[i] - nums[i - k]
     maxSum = max(maxSum, sum)
4. Return (double)maxSum / k.
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        long long maxSum = sum;

        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};
