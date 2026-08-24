// Link: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sliding Window: sum * length < k)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize left = 0, sum = 0, ans = 0.
2. For right from 0 to n-1:
     sum += nums[right]
     While sum * (right - left + 1) >= k:
         sum -= nums[left]
         left++
     ans += (right - left + 1)
3. Return ans.
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long sum = 0;
        long long ans = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            // Shrink window if score (sum * length) is >= k
            while (sum * (right - left + 1) >= k) {
                sum -= nums[left];
                left++;
            }

            // All subarrays ending at right with start in [left..right] have score < k
            ans += (right - left + 1);
        }

        return ans;
    }
};
