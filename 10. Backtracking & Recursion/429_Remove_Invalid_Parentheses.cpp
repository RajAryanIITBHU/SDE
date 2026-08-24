// Link: https://leetcode.com/problems/remove-invalid-parentheses/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (BFS Level-Order Minimum Removals)
// ==========================================
// Time Complexity  : O(2^n * n)
// Space Complexity : O(2^n)
/*
PSEUDOCODE:
1. Helper isValid(s):
     count = 0
     For c in s:
         if c == '(': count++
         else if c == ')':
             count--
             if count < 0 return false
     return count == 0
2. Queue q, push s, visited set containing s.
3. found = false, vector<string> ans.
4. While !q.empty():
     curr = q.front(), q.pop()
     if isValid(curr):
         ans.push_back(curr)
         found = true
     if found continue // Stop expanding deeper levels once valid string found at this level
     For i from 0 to curr.length() - 1:
         if curr[i] != '(' && curr[i] != ')' continue
         nextStr = curr.substr(0, i) + curr.substr(i + 1)
         if !vis.count(nextStr):
             vis.insert(nextStr)
             q.push(nextStr)
5. Return ans.
*/

class Solution {
private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> vis;
        queue<string> q;

        q.push(s);
        vis.insert(s);
        bool found = false;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (isValid(curr)) {
                ans.push_back(curr);
                found = true;
            }

            if (found) continue;

            for (int i = 0; i < (int)curr.length(); i++) {
                if (curr[i] != '(' && curr[i] != ')') continue;

                string nextStr = curr.substr(0, i) + curr.substr(i + 1);

                if (vis.find(nextStr) == vis.end()) {
                    vis.insert(nextStr);
                    q.push(nextStr);
                }
            }
        }

        return ans;
    }
};
