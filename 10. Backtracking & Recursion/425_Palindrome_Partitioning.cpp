// Link: https://leetcode.com/problems/palindrome-partitioning/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with Palindrome Substring Checks)
// ==========================================
// Time Complexity  : O(n * 2^n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Helper isPalindrome(s, left, right):
     While left < right:
         if s[left] != s[right] return false
         left++, right--
     return true
2. Helper backtrack(startIdx, s, currentPartition, ans):
     if startIdx == s.length():
         ans.push_back(currentPartition)
         return
     For endIdx from startIdx to s.length() - 1:
         if isPalindrome(s, startIdx, endIdx):
             currentPartition.push_back(s.substr(startIdx, endIdx - startIdx + 1))
             backtrack(endIdx + 1, s, currentPartition, ans)
             currentPartition.pop_back() // Backtrack
3. backtrack(0, s, currentPartition, ans).
4. Return ans.
*/

class Solution {
private:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void backtrack(int startIdx, const string& s, vector<string>& currentPartition, vector<vector<string>>& ans) {
        if (startIdx == (int)s.length()) {
            ans.push_back(currentPartition);
            return;
        }

        for (int endIdx = startIdx; endIdx < (int)s.length(); endIdx++) {
            if (isPalindrome(s, startIdx, endIdx)) {
                currentPartition.push_back(s.substr(startIdx, endIdx - startIdx + 1));
                backtrack(endIdx + 1, s, currentPartition, ans);
                currentPartition.pop_back(); // Backtrack
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> currentPartition;
        backtrack(0, s, currentPartition, ans);
        return ans;
    }
};
