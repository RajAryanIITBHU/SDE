// Link: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Three Pointer / Boundary Tracking)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Track three positions:
     minKPos = -1 (latest index of minK)
     maxKPos = -1 (latest index of maxK)
     badPos  = -1 (latest index of element < minK or > maxK)
2. Initialize ans = 0.
3. For i from 0 to n-1:
     if nums[i] < minK || nums[i] > maxK:
         badPos = i
     if nums[i] == minK:
         minKPos = i
     if nums[i] == maxK:
         maxKPos = i
     
     validStarts = min(minKPos, maxKPos) - badPos
     if validStarts > 0:
         ans += validStarts
4. Return ans.
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;

        int minKPos = -1;
        int maxKPos = -1;
        int badPos = -1;

        for (int i = 0; i < n; i++) {
            // Out of bounds element
            if (nums[i] < minK || nums[i] > maxK) {
                badPos = i;
            }

            if (nums[i] == minK) minKPos = i;
            if (nums[i] == maxK) maxKPos = i;

            // Number of valid subarray starting positions
            int validStarts = min(minKPos, maxKPos) - badPos;
            if (validStarts > 0) {
                ans += validStarts;
            }
        }

        return ans;
    }
};
