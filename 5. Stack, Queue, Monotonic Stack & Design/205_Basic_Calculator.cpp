// Link: https://leetcode.com/problems/basic-calculator/

#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sign & Result Stack with Parentheses)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize ans = 0, sign = 1, currentNumber = 0, stack<int> st.
2. For each char c in s:
     if isdigit(c) -> currentNumber = currentNumber * 10 + (c - '0')
     else if c == '+':
         ans += sign * currentNumber
         currentNumber = 0
         sign = 1
     else if c == '-':
         ans += sign * currentNumber
         currentNumber = 0
         sign = -1
     else if c == '(':
         st.push(ans)
         st.push(sign)
         ans = 0
         sign = 1
     else if c == ')':
         ans += sign * currentNumber
         currentNumber = 0
         prevSign = st.top(), st.pop()
         prevAns = st.top(), st.pop()
         ans = prevAns + prevSign * ans
3. ans += sign * currentNumber
4. Return ans.
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long long ans = 0;
        long long currentNumber = 0;
        int sign = 1; // 1 for '+', -1 for '-'

        for (char c : s) {
            if (isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            } else if (c == '+') {
                ans += sign * currentNumber;
                currentNumber = 0;
                sign = 1;
            } else if (c == '-') {
                ans += sign * currentNumber;
                currentNumber = 0;
                sign = -1;
            } else if (c == '(') {
                // Save current accumulated result and current sign
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            } else if (c == ')') {
                ans += sign * currentNumber;
                currentNumber = 0;

                int prevSign = st.top(); st.pop();
                int prevAns = st.top(); st.pop();

                ans = prevAns + (long long)prevSign * ans;
            }
        }

        ans += sign * currentNumber;
        return ans;
    }
};
