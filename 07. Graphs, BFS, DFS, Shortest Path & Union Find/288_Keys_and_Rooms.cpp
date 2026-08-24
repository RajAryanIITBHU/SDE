// Link: https://leetcode.com/problems/keys-and-rooms/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (BFS Reachability)
// ==========================================
// Time Complexity  : O(N + K), where N is rooms, K is total keys
// Space Complexity : O(N)
/*
PSEUDOCODE:
1. Initialize vis vector of size n with false, vis[0] = true.
2. Initialize queue<int> q, push 0, visitedCount = 1.
3. While !q.empty():
     room = q.front(), q.pop()
     For each key in rooms[room]:
         if !vis[key]:
             vis[key] = true
             visitedCount++
             q.push(key)
4. Return visitedCount == n.
*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        queue<int> q;

        vis[0] = true;
        q.push(0);
        int visitedCount = 1;

        while (!q.empty()) {
            int room = q.front();
            q.pop();

            for (int key : rooms[room]) {
                if (!vis[key]) {
                    vis[key] = true;
                    visitedCount++;
                    q.push(key);
                }
            }
        }

        return visitedCount == n;
    }
};
