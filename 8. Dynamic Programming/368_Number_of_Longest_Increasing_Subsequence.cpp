// Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (LIS DP with Count Array)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize len array of size n with 1, count array of size n with 1.
2. maxLen = 1.
3. For i from 0 to n-1:
     For j from 0 to i-1:
         if nums[i] > nums[j]:
             if len[j] + 1 > len[i]:
                 len[i] = len[j] + 1
                 count[i] = count[j]
             else if len[j] + 1 == len[i]:
                 count[i] += count[j]
     maxLen = max(maxLen, len[i])
4. Total count = sum of count[i] for all i where len[i] == maxLen.
5. Return total count.
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        vector<int> len(n, 1);
        vector<int> count(n, 1);
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        count[i] = count[j];
                    } else if (len[j] + 1 == len[i]) {
                        count[i] += count[j];
                    }
                }
            }
            maxLen = max(maxLen, len[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (len[i] == maxLen) {
                ans += count[i];
            }
        }

        return ans;
    }
};
