// Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Stack Evaluation)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize stack<int> st.
2. For each token in tokens:
     if token is operator (+, -, *, /):
         op2 = st.top(), st.pop()
         op1 = st.top(), st.pop()
         if token == "+" -> st.push(op1 + op2)
         else if token == "-" -> st.push(op1 - op2)
         else if token == "*" -> st.push(op1 * op2)
         else if token == "/" -> st.push(op1 / op2)
     else:
         st.push(stoi(token))
3. Return st.top().
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();

                if (token == "+") st.push(op1 + op2);
                else if (token == "-") st.push(op1 - op2);
                else if (token == "*") st.push(op1 * op2);
                else if (token == "/") st.push(op1 / op2);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
