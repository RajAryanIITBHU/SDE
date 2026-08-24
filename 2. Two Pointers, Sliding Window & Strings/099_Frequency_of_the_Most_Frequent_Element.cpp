// Link: https://leetcode.com/problems/frequency-of-the-most-frequent-element/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sorting + Sliding Window)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Sort nums in ascending order.
2. Maintain sliding window [left, right] where we try to make all elements equal to nums[right].
3. Operations needed = nums[right] * (right - left + 1) - windowSum.
4. If operations > k:
     windowSum -= nums[left]
     left++
5. ans = max(ans, right - left + 1).
6. Return ans.
*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int left = 0;
        long long windowSum = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            windowSum += nums[right];

            // Operations needed to make all elements in [left, right] equal to nums[right]
            while ((long long)nums[right] * (right - left + 1) - windowSum > k) {
                windowSum -= nums[left];
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
