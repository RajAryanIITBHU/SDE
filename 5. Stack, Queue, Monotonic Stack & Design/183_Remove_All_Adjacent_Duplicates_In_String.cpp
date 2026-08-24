// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (String as Stack)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n) for result string
/*
PSEUDOCODE:
1. Initialize string ans = "".
2. For each char c in s:
     if !ans.empty() && ans.back() == c:
         ans.pop_back()
     else:
         ans.push_back(c)
3. Return ans.
*/

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";

        for (char c : s) {
            // If top of stack matches current character, pop duplicate
            if (!ans.empty() && ans.back() == c) {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }

        return ans;
    }
};
