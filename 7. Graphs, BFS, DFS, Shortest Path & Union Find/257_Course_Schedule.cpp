// Link: https://leetcode.com/problems/course-schedule/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Kahn's Algorithm - BFS Topological Sort)
// ==========================================
// Time Complexity  : O(V + E)
// Space Complexity : O(V + E)
/*
PSEUDOCODE:
1. Build adjacency list adj and compute inDegree for all courses.
2. Initialize queue q, push all courses with inDegree == 0.
3. processedCount = 0.
4. While !q.empty():
     u = q.front(), q.pop()
     processedCount++
     For each v in adj[u]:
         inDegree[v]--
         if inDegree[v] == 0 -> q.push(v)
5. Return processedCount == numCourses.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int processedCount = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            processedCount++;

            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return processedCount == numCourses;
    }
};
