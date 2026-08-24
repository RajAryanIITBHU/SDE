// Link: https://leetcode.com/problems/expression-add-operators/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with Previous Operand Tracking)
// ==========================================
// Time Complexity  : O(4^n * n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Helper backtrack(idx, num, target, expr, currentVal, prevOperand, ans):
     if idx == num.length():
         if currentVal == target -> ans.push_back(expr)
         return
     For len from 1 to num.length() - idx:
         part = num.substr(idx, len)
         if part.length() > 1 && part[0] == '0' break // No leading zeroes
         curr = stoll(part)
         if idx == 0:
             backtrack(idx + len, num, target, part, curr, curr, ans)
         else:
             backtrack(idx + len, num, target, expr + "+" + part, currentVal + curr, curr, ans)
             backtrack(idx + len, num, target, expr + "-" + part, currentVal - curr, -curr, ans)
             backtrack(idx + len, num, target, expr + "*" + part, currentVal - prevOperand + prevOperand * curr, prevOperand * curr, ans)
2. backtrack(0, num, target, "", 0, 0, ans).
3. Return ans.
*/

class Solution {
private:
    void backtrack(int idx, const string& num, int target, string expr, long long currentVal, long long prevOperand, vector<string>& ans) {
        if (idx == (int)num.length()) {
            if (currentVal == target) {
                ans.push_back(expr);
            }
            return;
        }

        for (int len = 1; len <= (int)num.length() - idx; len++) {
            string part = num.substr(idx, len);
            if (part.length() > 1 && part[0] == '0') break; // Disallow leading zeros

            long long curr = stoll(part);

            if (idx == 0) {
                backtrack(idx + len, num, target, part, curr, curr, ans);
            } else {
                // Addition '+'
                backtrack(idx + len, num, target, expr + "+" + part, currentVal + curr, curr, ans);

                // Subtraction '-'
                backtrack(idx + len, num, target, expr + "-" + part, currentVal - curr, -curr, ans);

                // Multiplication '*' (Account for precedence: subtract prevOperand, add prevOperand * curr)
                backtrack(idx + len, num, target, expr + "*" + part, currentVal - prevOperand + prevOperand * curr, prevOperand * curr, ans);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        backtrack(0, num, target, "", 0, 0, ans);
        return ans;
    }
};
