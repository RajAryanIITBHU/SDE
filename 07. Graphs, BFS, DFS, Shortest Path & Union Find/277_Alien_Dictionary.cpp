// Link: https://leetcode.com/problems/alien-dictionary/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Graph Construction + Kahn's Algorithm)
// ==========================================
// Time Complexity  : O(C), total length of all words in alien dictionary
// Space Complexity : O(U + min(U^2, N)), where U is unique characters (<= 26)
/*
PSEUDOCODE:
1. Initialize inDegree map for all unique characters.
2. Compare adjacent words w1 and w2:
     if w1.length() > w2.length() && w1.substr(0, w2.length()) == w2 -> return "" (invalid prefix ordering)
     Find first differing character: w1[j] -> w2[j]
     Add directed edge w1[j] -> w2[j] in adj, inDegree[w2[j]]++
3. Push all characters with inDegree == 0 into queue q.
4. Topological Sort:
     While !q.empty():
         c = q.front(), q.pop()
         ans += c
         For each neighbor in adj[c]:
             inDegree[neighbor]--
             if inDegree[neighbor] == 0 -> q.push(neighbor)
5. Return ans.length() == inDegree.size() ? ans : "".
*/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;

        // Initialize inDegree for all unique characters
        for (string& w : words) {
            for (char c : w) {
                inDegree[c] = 0;
            }
        }

        // Build directed graph edges
        for (int i = 0; i < (int)words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            // Invalid prefix case, e.g., ["abc", "ab"]
            if (w1.length() > w2.length() && w1.rfind(w2, 0) == 0) {
                return "";
            }

            for (int j = 0; j < (int)min(w1.length(), w2.length()); j++) {
                if (w1[j] != w2[j]) {
                    char u = w1[j];
                    char v = w2[j];

                    if (adj[u].find(v) == adj[u].end()) {
                        adj[u].insert(v);
                        inDegree[v]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for (auto& p : inDegree) {
            if (p.second == 0) {
                q.push(p.first);
            }
        }

        string ans = "";

        while (!q.empty()) {
            char u = q.front();
            q.pop();
            ans += u;

            for (char v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return (ans.length() == inDegree.size()) ? ans : "";
    }
};
