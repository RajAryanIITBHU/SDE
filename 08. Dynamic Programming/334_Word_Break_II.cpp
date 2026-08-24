// Link: https://leetcode.com/problems/word-break-ii/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (DFS + Memoization)
// ==========================================
// Time Complexity  : O(2^n) worst case
// Space Complexity : O(2^n * n)
/*
PSEUDOCODE:
1. Store wordDict in unordered_set dict.
2. Helper dfs(s, dict, memo):
     if memo contains s return memo[s]
     if s is empty return {""}
     vector<string> res
     For word in dict:
         if s starts with word:
             subResults = dfs(s.substr(word.length()), dict, memo)
             For sub in subResults:
                 res.push_back(word + (sub.empty() ? "" : " ") + sub)
     return memo[s] = res
3. Return dfs(s, dict, memo).
*/

class Solution {
private:
    unordered_map<string, vector<string>> memo;

    vector<string> dfs(string s, unordered_set<string>& dict) {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }

        if (s.empty()) {
            return {""};
        }

        vector<string> res;

        for (const string& word : dict) {
            if (s.rfind(word, 0) == 0) { // s starts with word
                vector<string> subResults = dfs(s.substr(word.length()), dict);

                for (const string& sub : subResults) {
                    res.push_back(word + (sub.empty() ? "" : " ") + sub);
                }
            }
        }

        return memo[s] = res;
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(s, dict);
    }
};
