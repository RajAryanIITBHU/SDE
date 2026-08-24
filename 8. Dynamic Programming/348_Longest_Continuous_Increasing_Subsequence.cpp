// Link: https://leetcode.com/problems/longest-continuous-increasing-subsequence/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Single Pass Sliding Counter)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If nums.empty() return 0.
2. maxLen = 1, currentLen = 1.
3. For i from 1 to n-1:
     if nums[i] > nums[i - 1]:
         currentLen++
     else:
         currentLen = 1
     maxLen = max(maxLen, currentLen)
4. Return maxLen.
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxLen = 1;
        int currentLen = 1;

        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currentLen++;
            } else {
                currentLen = 1;
            }

            maxLen = max(maxLen, currentLen);
        }

        return maxLen;
    }
};
