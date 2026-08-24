// Link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Hash Map Dynamic Programming)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain dp map: value -> longestAPEndingHere.
2. maxLen = 1.
3. For each x in arr:
     dp[x] = dp[x - difference] + 1
     maxLen = max(maxLen, dp[x])
4. Return maxLen.
*/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int maxLen = 1;

        for (int x : arr) {
            dp[x] = dp[x - difference] + 1;
            maxLen = max(maxLen, dp[x]);
        }

        return maxLen;
    }
};
