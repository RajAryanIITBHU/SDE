// Link: https://leetcode.com/problems/reorganize-string/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Max-Heap Frequency Greedy Scheduling)
// ==========================================
// Time Complexity  : O(n log 26) = O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Count char frequencies in freq map.
2. Max-heap pq storing {count, char}.
3. prev = {-1, '#'}.
4. string ans = "".
5. While !pq.empty():
     {count, c} = pq.top(), pq.pop()
     ans += c
     if prev.first > 0:
         pq.push(prev)
     prev = {count - 1, c}
6. Return ans.length() == s.length() ? ans : "".
*/

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        priority_queue<pair<int, char>> pq;
        for (auto& p : freq) {
            pq.push({p.second, p.first});
        }

        pair<int, char> prev = {-1, '#'};
        string ans = "";

        while (!pq.empty()) {
            auto [count, c] = pq.top();
            pq.pop();

            ans += c;

            // Push back previously held character
            if (prev.first > 0) {
                pq.push(prev);
            }

            prev = {count - 1, c};
        }

        return (ans.length() == s.length()) ? ans : "";
    }
};
