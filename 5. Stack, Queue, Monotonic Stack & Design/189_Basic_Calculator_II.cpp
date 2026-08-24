// Link: https://leetcode.com/problems/basic-calculator-ii/

#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <numeric>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Stack with Operator Precedence)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain stack<int> st, currentNumber = 0, operation = '+'.
2. For i from 0 to n-1:
     c = s[i]
     if isdigit(c) -> currentNumber = currentNumber * 10 + (c - '0')
     if (!isdigit(c) && !isspace(c)) || i == n - 1:
         if operation == '+' -> st.push(currentNumber)
         else if operation == '-' -> st.push(-currentNumber)
         else if operation == '*':
             top = st.top(), st.pop()
             st.push(top * currentNumber)
         else if operation == '/':
             top = st.top(), st.pop()
             st.push(top / currentNumber)
         operation = c
         currentNumber = 0
3. Sum all elements in st and return.
*/

class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> st;
        long long currentNumber = 0;
        char operation = '+';

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            }

            if ((!isdigit(c) && !isspace(c)) || i == n - 1) {
                if (operation == '+') {
                    st.push(currentNumber);
                } else if (operation == '-') {
                    st.push(-currentNumber);
                } else if (operation == '*') {
                    int top = st.top(); st.pop();
                    st.push(top * currentNumber);
                } else if (operation == '/') {
                    int top = st.top(); st.pop();
                    st.push(top / currentNumber);
                }

                operation = c;
                currentNumber = 0;
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
