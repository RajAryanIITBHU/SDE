// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with Mapping)
// ==========================================
// Time Complexity  : O(4^n * n)
// Space Complexity : O(n) recursion stack
/*
PSEUDOCODE:
1. Mapping array phoneMap: "2" -> "abc", "3" -> "def", etc.
2. Helper backtrack(idx, digits, currentComb, ans):
     if idx == digits.length():
         ans.push_back(currentComb)
         return
     letters = phoneMap[digits[idx] - '0']
     For each c in letters:
         backtrack(idx + 1, digits, currentComb + c, ans)
3. If digits.empty() return {}.
4. backtrack(0, digits, "", ans).
5. Return ans.
*/

class Solution {
private:
    vector<string> phoneMap = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(int idx, const string& digits, string currentComb, vector<string>& ans) {
        if (idx == (int)digits.length()) {
            ans.push_back(currentComb);
            return;
        }

        const string& letters = phoneMap[digits[idx] - '0'];
        for (char c : letters) {
            backtrack(idx + 1, digits, currentComb + c, ans);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> ans;
        backtrack(0, digits, "", ans);
        return ans;
    }
};
