// Link: https://leetcode.com/problems/rearrange-string-k-distance-apart/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Max-Heap with Cooldown Queue)
// ==========================================
// Time Complexity  : O(n log 26) = O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. If k <= 1 return s.
2. Count char frequencies in freq map.
3. Max-heap pq storing {count, char}.
4. Queue cooldown storing {count, char}.
5. string ans = "".
6. While !pq.empty():
     {count, c} = pq.top(), pq.pop()
     ans += c
     cooldown.push({count - 1, c})
     if cooldown.size() >= k:
         frontItem = cooldown.front(), cooldown.pop()
         if frontItem.first > 0:
             pq.push(frontItem)
7. Return ans.length() == s.length() ? ans : "".
*/

class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k <= 1) return s;

        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto& p : freq) {
            pq.push({p.second, p.first});
        }

        queue<pair<int, char>> cooldown;
        string ans = "";

        while (!pq.empty()) {
            auto [count, c] = pq.top();
            pq.pop();

            ans += c;
            cooldown.push({count - 1, c});

            if ((int)cooldown.size() >= k) {
                auto frontItem = cooldown.front();
                cooldown.pop();

                if (frontItem.first > 0) {
                    pq.push(frontItem);
                }
            }
        }

        return (ans.length() == s.length()) ? ans : "";
    }
};
