// Link: https://leetcode.com/problems/subarray-product-less-than-k/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sliding Window: Product < K)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If k <= 1 return 0 (since elements are positive integers).
2. Initialize prod = 1, left = 0, ans = 0.
3. For right from 0 to n-1:
     prod *= nums[right]
     While prod >= k:
         prod /= nums[left]
         left++
     ans += (right - left + 1) // Number of subarrays ending at right
4. Return ans.
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int n = nums.size();
        long long prod = 1;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            prod *= nums[right];

            // Shrink window if product is >= k
            while (prod >= k && left <= right) {
                prod /= nums[left];
                left++;
            }

            // All subarrays ending at right and starting from left..right are valid
            ans += (right - left + 1);
        }

        return ans;
    }
};
