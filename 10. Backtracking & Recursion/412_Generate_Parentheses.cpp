// Link: https://leetcode.com/problems/generate-parentheses/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with Open & Close Constraints)
// ==========================================
// Time Complexity  : O(4^n / sqrt(n)) - nth Catalan number
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Helper backtrack(currentStr, openCount, closeCount, n, ans):
     if currentStr.length() == 2 * n:
         ans.push_back(currentStr)
         return
     if openCount < n:
         backtrack(currentStr + '(', openCount + 1, closeCount, n, ans)
     if closeCount < openCount:
         backtrack(currentStr + ')', openCount, closeCount + 1, n, ans)
2. backtrack("", 0, 0, n, ans).
3. Return ans.
*/

class Solution {
private:
    void backtrack(string currentStr, int openCount, int closeCount, int n, vector<string>& ans) {
        if ((int)currentStr.length() == 2 * n) {
            ans.push_back(currentStr);
            return;
        }

        if (openCount < n) {
            backtrack(currentStr + '(', openCount + 1, closeCount, n, ans);
        }

        if (closeCount < openCount) {
            backtrack(currentStr + ')', openCount, closeCount + 1, n, ans);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack("", 0, 0, n, ans);
        return ans;
    }
};
