// Link: https://leetcode.com/problems/simplify-path/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (StringStream Tokenization + Vector Stack)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Use stringstream and getline with delimiter '/' to extract directory tokens.
2. Maintain vector<string> st as a stack.
3. For each token:
     if token == "" || token == "." -> continue
     else if token == "..":
         if !st.empty() -> st.pop_back()
     else:
         st.push_back(token)
4. Reconstruct canonical path:
     if st.empty() -> return "/"
     ans = ""
     For each dir in st: ans += "/" + dir
5. Return ans.
*/

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> st;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!st.empty()) {
                    st.pop_back(); // Move up one directory level
                }
            } else {
                st.push_back(token); // Valid directory name
            }
        }

        if (st.empty()) return "/";

        string ans = "";
        for (string& dir : st) {
            ans += "/" + dir;
        }

        return ans;
    }
};
