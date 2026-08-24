// Link: https://leetcode.com/problems/max-consecutive-ones-iii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sliding Window: At Most K Zeros)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize left = 0, zeroCount = 0, ans = 0.
2. For right from 0 to n-1:
     if nums[right] == 0 -> zeroCount++
     While zeroCount > k:
         if nums[left] == 0 -> zeroCount--
         left++
     ans = max(ans, right - left + 1)
3. Return ans.
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int zeroCount = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                zeroCount++;
            }

            // Shrink window when zeros exceed k
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
