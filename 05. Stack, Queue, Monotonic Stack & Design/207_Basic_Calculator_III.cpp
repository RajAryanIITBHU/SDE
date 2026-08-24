// Link: https://leetcode.com/problems/basic-calculator-iii/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Recursive Descent / Stack with Parentheses & Operators)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Helper parse(s, i):
     Maintain vector<int> st as stack, currentNumber = 0, op = '+'.
     While i < s.length():
         c = s[i]
         if isdigit(c) -> currentNumber = currentNumber * 10 + (c - '0')
         if c == '(':
             currentNumber = parse(s, ++i)
         if (!isdigit(c) && !isspace(c)) || i == s.length() - 1 || c == ')':
             if op == '+' -> st.push_back(currentNumber)
             else if op == '-' -> st.push_back(-currentNumber)
             else if op == '*':
                 st.back() = st.back() * currentNumber
             else if op == '/':
                 st.back() = st.back() / currentNumber
             op = c
             currentNumber = 0
         if c == ')' -> break
         i++
     Return sum of st.
*/

class Solution {
private:
    int parse(string& s, int& i) {
        vector<long long> st;
        long long currentNumber = 0;
        char op = '+';

        while (i < (int)s.length()) {
            char c = s[i];

            if (isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            } else if (c == '(') {
                i++;
                currentNumber = parse(s, i);
            }

            if ((!isdigit(c) && !isspace(c)) || i == (int)s.length() - 1) {
                if (op == '+') {
                    st.push_back(currentNumber);
                } else if (op == '-') {
                    st.push_back(-currentNumber);
                } else if (op == '*') {
                    st.back() = st.back() * currentNumber;
                } else if (op == '/') {
                    st.back() = st.back() / currentNumber;
                }

                op = c;
                currentNumber = 0;
            }

            if (c == ')') {
                break;
            }

            i++;
        }

        long long sum = 0;
        for (long long val : st) {
            sum += val;
        }

        return (int)sum;
    }

public:
    int calculate(string s) {
        int i = 0;
        return parse(s, i);
    }
};
