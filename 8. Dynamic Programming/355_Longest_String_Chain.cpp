// Link: https://leetcode.com/problems/longest-string-chain/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sorting by Length + Hash Map DP)
// ==========================================
// Time Complexity  : O(N log N + N * L^2), where L is max word length (<= 16)
// Space Complexity : O(N)
/*
PSEUDOCODE:
1. Sort words by length in ascending order.
2. Maintain dp map: word -> longestChainEndingHere.
3. maxChain = 1.
4. For each word in words:
     dp[word] = 1
     For i from 0 to word.length() - 1:
         predecessor = word with character at index i removed
         if predecessor in dp:
             dp[word] = max(dp[word], dp[predecessor] + 1)
     maxChain = max(maxChain, dp[word])
5. Return maxChain.
*/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        unordered_map<string, int> dp;
        int maxChain = 1;

        for (const string& word : words) {
            dp[word] = 1;

            // Generate all possible predecessor strings by deleting 1 character
            for (int i = 0; i < (int)word.length(); i++) {
                string pred = word.substr(0, i) + word.substr(i + 1);

                if (dp.find(pred) != dp.end()) {
                    dp[word] = max(dp[word], dp[pred] + 1);
                }
            }

            maxChain = max(maxChain, dp[word]);
        }

        return maxChain;
    }
};
