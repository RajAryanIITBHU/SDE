// Link: https://leetcode.com/problems/letter-case-permutation/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking Binary Tree DFS)
// ==========================================
// Time Complexity  : O(2^n * n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Helper backtrack(idx, s, ans):
     if idx == s.length():
         ans.push_back(s)
         return
     if isalpha(s[idx]):
         s[idx] = tolower(s[idx])
         backtrack(idx + 1, s, ans)
         s[idx] = toupper(s[idx])
         backtrack(idx + 1, s, ans)
     else:
         backtrack(idx + 1, s, ans)
2. backtrack(0, s, ans).
3. Return ans.
*/

class Solution {
private:
    void backtrack(int idx, string& s, vector<string>& ans) {
        if (idx == (int)s.length()) {
            ans.push_back(s);
            return;
        }

        if (isalpha(s[idx])) {
            s[idx] = tolower(s[idx]);
            backtrack(idx + 1, s, ans);

            s[idx] = toupper(s[idx]);
            backtrack(idx + 1, s, ans);
        } else {
            backtrack(idx + 1, s, ans);
        }
    }

public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        backtrack(0, s, ans);
        return ans;
    }
};
