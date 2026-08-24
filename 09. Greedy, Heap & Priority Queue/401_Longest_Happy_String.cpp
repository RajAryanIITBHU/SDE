// Link: https://leetcode.com/problems/longest-happy-string/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Max-Heap Greedy Character Selection)
// ==========================================
// Time Complexity  : O(a + b + c)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Max-heap pq storing {count, char} for non-zero counts.
2. string ans = "".
3. While !pq.empty():
     {count1, c1} = pq.top(), pq.pop()
     len = ans.length()
     if len >= 2 && ans[len - 1] == c1 && ans[len - 2] == c1:
         if pq.empty() break // Cannot place c1 and no alternate char exists
         {count2, c2} = pq.top(), pq.pop()
         ans += c2
         if (count2 - 1) > 0: pq.push({count2 - 1, c2})
         pq.push({count1, c1})
     else:
         ans += c1
         if (count1 - 1) > 0: pq.push({count1 - 1, c1})
4. Return ans.
*/

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans = "";

        while (!pq.empty()) {
            auto [count1, c1] = pq.top();
            pq.pop();

            int len = ans.length();
            if (len >= 2 && ans[len - 1] == c1 && ans[len - 2] == c1) {
                if (pq.empty()) break; // Cannot use c1, and no alternative character available

                auto [count2, c2] = pq.top();
                pq.pop();

                ans += c2;
                if (count2 - 1 > 0) pq.push({count2 - 1, c2});
                pq.push({count1, c1});
            } else {
                ans += c1;
                if (count1 - 1 > 0) pq.push({count1 - 1, c1});
            }
        }

        return ans;
    }
};
