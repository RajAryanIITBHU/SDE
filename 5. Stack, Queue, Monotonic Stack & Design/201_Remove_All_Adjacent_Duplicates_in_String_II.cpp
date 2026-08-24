// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Stack of Pairs: {char, count})
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain vector<pair<char, int>> st as stack.
2. For each char c in s:
     if !st.empty() && st.back().first == c:
         st.back().second++
         if st.back().second == k:
             st.pop_back() // Remove k duplicates
     else:
         st.push_back({c, 1})
3. Reconstruct result string from st and return.
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st; // {char, consecutiveCount}

        for (char c : s) {
            if (!st.empty() && st.back().first == c) {
                st.back().second++;
                if (st.back().second == k) {
                    st.pop_back(); // Remove block of k adjacent identical characters
                }
            } else {
                st.push_back({c, 1});
            }
        }

        string ans = "";
        for (auto& p : st) {
            ans.append(p.second, p.first);
        }

        return ans;
    }
};
