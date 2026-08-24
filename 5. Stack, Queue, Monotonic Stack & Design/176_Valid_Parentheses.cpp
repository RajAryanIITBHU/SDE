// Link: https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Stack Matching)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize stack<char> st.
2. For each char c in s:
     if c == '(' -> st.push(')')
     else if c == '{' -> st.push('}')
     else if c == '[' -> st.push(']')
     else: // Closing bracket
         if st.empty() || st.top() != c -> return false
         st.pop()
3. Return st.empty().
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // Push expected closing brackets
            if (c == '(') {
                st.push(')');
            } else if (c == '{') {
                st.push('}');
            } else if (c == '[') {
                st.push(']');
            } else {
                if (st.empty() || st.top() != c) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};
