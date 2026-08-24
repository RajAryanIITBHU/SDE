// Link: https://leetcode.com/problems/open-the-lock/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (BFS Shortest Path in State Graph)
// ==========================================
// Time Complexity  : O(10^4 * 8) = O(80,000)
// Space Complexity : O(10^4)
/*
PSEUDOCODE:
1. Store deadends in unordered_set deadSet.
2. If "0000" in deadSet return -1.
3. If target == "0000" return 0.
4. Initialize queue<string> q, push "0000", mark visited, turns = 0.
5. While !q.empty():
     levelSize = q.size()
     For i from 0 to levelSize - 1:
         curr = q.front(), q.pop()
         if curr == target return turns
         Generate 8 neighbors by rotating each of the 4 wheels +1 and -1:
             if neighbor not in deadSet and not in visited:
                 mark visited, q.push(neighbor)
     turns++
6. Return -1.
*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        if (target == "0000") return 0;

        unordered_set<string> vis;
        queue<string> q;

        q.push("0000");
        vis.insert("0000");
        int turns = 0;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                string curr = q.front();
                q.pop();

                if (curr == target) {
                    return turns;
                }

                // Generate 8 adjacent lock combinations
                for (int j = 0; j < 4; j++) {
                    char orig = curr[j];

                    // Turn up
                    curr[j] = (orig == '9') ? '0' : orig + 1;
                    if (!dead.count(curr) && !vis.count(curr)) {
                        vis.insert(curr);
                        q.push(curr);
                    }

                    // Turn down
                    curr[j] = (orig == '0') ? '9' : orig - 1;
                    if (!dead.count(curr) && !vis.count(curr)) {
                        vis.insert(curr);
                        q.push(curr);
                    }

                    curr[j] = orig; // Reset
                }
            }

            turns++;
        }

        return -1;
    }
};
