// Link: https://leetcode.com/problems/decode-string/

#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Dual Stack: Counts & String Prefixes)
// ==========================================
// Time Complexity  : O(decoded_string_length)
// Space Complexity : O(decoded_string_length)
/*
PSEUDOCODE:
1. Initialize countStack and strStack.
2. currStr = "", currNum = 0.
3. For each char c in s:
     if isdigit(c) -> currNum = currNum * 10 + (c - '0')
     else if c == '[':
         countStack.push(currNum)
         strStack.push(currStr)
         currNum = 0
         currStr = ""
     else if c == ']':
         k = countStack.top(), countStack.pop()
         prevStr = strStack.top(), strStack.pop()
         repeated = ""
         While k-- > 0: repeated += currStr
         currStr = prevStr + repeated
     else:
         currStr += c
4. Return currStr.
*/

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> strStack;

        string currStr = "";
        int currNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                currNum = currNum * 10 + (c - '0');
            } else if (c == '[') {
                countStack.push(currNum);
                strStack.push(currStr);
                currNum = 0;
                currStr = "";
            } else if (c == ']') {
                int repeatTimes = countStack.top(); countStack.pop();
                string prevStr = strStack.top(); strStack.pop();

                string repeated = "";
                while (repeatTimes--) {
                    repeated += currStr;
                }

                currStr = prevStr + repeated;
            } else {
                currStr += c;
            }
        }

        return currStr;
    }
};
