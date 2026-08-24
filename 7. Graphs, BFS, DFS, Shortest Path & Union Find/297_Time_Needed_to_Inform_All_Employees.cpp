// Link: https://leetcode.com/problems/time-needed-to-inform-all-employees/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (DFS Tree Traversal with Time Accumulation)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Build subordinates adjacency tree: adj[manager[i]].push_back(i).
2. Helper dfs(u):
     maxSubTime = 0
     For each sub in adj[u]:
         maxSubTime = max(maxSubTime, dfs(sub))
     return informTime[u] + maxSubTime
3. Return dfs(headID).
*/

class Solution {
private:
    int dfs(int u, vector<vector<int>>& adj, vector<int>& informTime) {
        int maxSubTime = 0;

        for (int sub : adj[u]) {
            maxSubTime = max(maxSubTime, dfs(sub, adj, informTime));
        }

        return informTime[u] + maxSubTime;
    }

public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }

        return dfs(headID, adj, informTime);
    }
};
