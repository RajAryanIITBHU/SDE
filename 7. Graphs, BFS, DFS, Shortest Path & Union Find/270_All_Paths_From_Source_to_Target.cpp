// Link: https://leetcode.com/problems/all-paths-from-source-to-target/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (DAG DFS Backtracking)
// ==========================================
// Time Complexity  : O(2^V * V)
// Space Complexity : O(V) path recursion stack
/*
PSEUDOCODE:
1. Helper dfs(u, target, currentPath, ans, graph):
     currentPath.push_back(u)
     if u == target:
         ans.push_back(currentPath)
     else:
         For each v in graph[u]:
             dfs(v, target, currentPath, ans, graph)
     currentPath.pop_back() // Backtrack
2. dfs(0, n - 1, currentPath, ans, graph).
3. Return ans.
*/

class Solution {
private:
    void dfs(int u, int target, vector<int>& currentPath, vector<vector<int>>& ans, vector<vector<int>>& graph) {
        currentPath.push_back(u);

        if (u == target) {
            ans.push_back(currentPath);
        } else {
            for (int v : graph[u]) {
                dfs(v, target, currentPath, ans, graph);
            }
        }

        currentPath.pop_back(); // Backtrack
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size() - 1;
        vector<vector<int>> ans;
        vector<int> currentPath;

        dfs(0, target, currentPath, ans, graph);

        return ans;
    }
};
