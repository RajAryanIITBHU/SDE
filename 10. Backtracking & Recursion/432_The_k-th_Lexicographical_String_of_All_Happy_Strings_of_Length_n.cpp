// Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with K Counter)
// ==========================================
// Time Complexity  : O(2^n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Helper backtrack(currentStr, n, k, count, ans):
     if currentStr.length() == n:
         count++
         if count == k:
             ans = currentStr
             return true
         return false
     For c in {'a', 'b', 'c'}:
         if currentStr.empty() || currentStr.back() != c:
             if backtrack(currentStr + c, n, k, count, ans) return true
     return false
2. backtrack("", n, k, count, ans).
3. Return ans.
*/

class Solution {
private:
    bool backtrack(string currentStr, int n, int k, int& count, string& ans) {
        if ((int)currentStr.length() == n) {
            count++;
            if (count == k) {
                ans = currentStr;
                return true;
            }
            return false;
        }

        for (char c : {'a', 'b', 'c'}) {
            if (currentStr.empty() || currentStr.back() != c) {
                if (backtrack(currentStr + c, n, k, count, ans)) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    string getHappyString(int n, int k) {
        string ans = "";
        int count = 0;
        backtrack("", n, k, count, ans);
        return ans;
    }
};
