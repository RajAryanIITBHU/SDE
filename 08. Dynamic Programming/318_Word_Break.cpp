// Link: https://leetcode.com/problems/word-break/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D DP Array)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n + total_word_dict_chars)
/*
PSEUDOCODE:
1. Store wordDict in unordered_set dict.
2. Initialize dp array of size n+1 with false, dp[0] = true.
3. For i from 1 to n:
     For j from 0 to i-1:
         if dp[j] && dict.count(s.substr(j, i - j)):
             dp[i] = true
             break
4. Return dp[n].
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);

        dp[0] = true; // Empty string is always valid

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
