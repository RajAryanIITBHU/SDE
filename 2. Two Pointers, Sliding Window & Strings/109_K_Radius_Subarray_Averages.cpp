// Link: https://leetcode.com/problems/k-radius-subarray-averages/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Prefix Sum / Fixed Sliding Window of Size 2k + 1)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n) for prefix sum or O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. Initialize ans array of size n with -1.
2. windowSize = 2 * k + 1.
3. If windowSize > n return ans.
4. Calculate sum of first windowSize elements.
5. ans[k] = sum / windowSize.
6. For i from windowSize to n-1:
     sum += nums[i] - nums[i - windowSize]
     ans[i - k] = sum / windowSize
7. Return ans.
*/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);

        long long windowSize = 2LL * k + 1;
        if (windowSize > n) return ans;

        long long sum = 0;
        for (int i = 0; i < windowSize; i++) {
            sum += nums[i];
        }

        ans[k] = sum / windowSize;

        for (int i = windowSize; i < n; i++) {
            sum += nums[i] - nums[i - windowSize];
            ans[i - k] = sum / windowSize;
        }

        return ans;
    }
};
