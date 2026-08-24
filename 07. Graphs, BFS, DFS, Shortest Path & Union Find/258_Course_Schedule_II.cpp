// Link: https://leetcode.com/problems/course-schedule-ii/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Kahn's Algorithm - Topological Order Output)
// ==========================================
// Time Complexity  : O(V + E)
// Space Complexity : O(V + E)
/*
PSEUDOCODE:
1. Build adjacency list adj and inDegree array.
2. Push all nodes with inDegree == 0 into queue q.
3. vector<int> ans.
4. While !q.empty():
     u = q.front(), q.pop()
     ans.push_back(u)
     For each v in adj[u]:
         inDegree[v]--
         if inDegree[v] == 0 -> q.push(v)
5. Return ans.size() == numCourses ? ans : {}.
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);

            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return (ans.size() == numCourses) ? ans : vector<int>();
    }
};
