/*
 * ============================================================================
 * Concept: Topological Sort (Kahn's Algorithm & DFS)
 * Subtopic: Graphs, BFS, DFS, Shortest Path & Union Find
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Linear ordering of vertices in a Directed Acyclic Graph (DAG) such that for every edge `u -> v`, `u` comes before `v`.
Kahn's Algorithm:
1. Compute indegrees of all vertices.
2. Push vertices with `indegree == 0` into queue.
3. Pop vertex `u`, append to topological order, decrement indegree of neighbors `v`. If `indegree[v] == 0`, push `v`.
4. If result length < V, graph contains a cycle!
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(V + E) time complexity.
 * - Space Complexity: O(V + E) adjacency list and indegree array space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Course Schedule I & II (LC 207, 210).
- Alien Dictionary (LC 269).
- Find Eventual Safe States (LC 802).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Course Schedule II (Kahn's Algorithm).
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    for (const auto& p : prerequisites) {
        adj[p[1]].push_back(p[0]);
        indegree[p[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }
    return order.size() == (size_t)numCourses ? order : vector<int>();
}

int main() {
    vector<vector<int>> prereqs = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    auto order = findOrder(4, prereqs);
    cout << "Topological Order: ";
    for (int x : order) cout << x << " ";
    cout << "\n";
    return 0;
}
