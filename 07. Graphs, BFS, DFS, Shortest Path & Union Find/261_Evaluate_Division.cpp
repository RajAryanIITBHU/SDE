// Link: https://leetcode.com/problems/evaluate-division/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Weighted Graph DFS Traversal)
// ==========================================
// Time Complexity  : O(Q * (V + E))
// Space Complexity : O(V + E)
/*
PSEUDOCODE:
1. Build adjacency list: adj[u] = list of {v, weight}, adj[v] = list of {u, 1.0 / weight}.
2. Helper dfs(u, target, currentProduct, visited):
     if u == target return currentProduct
     visited.insert(u)
     For each {v, weight} in adj[u]:
         if v not in visited:
             res = dfs(v, target, currentProduct * weight, visited)
             if res != -1.0 return res
     return -1.0
3. For each query {src, dst}:
     if src not in adj || dst not in adj -> ans.push_back(-1.0)
     else -> ans.push_back(dfs(src, dst, 1.0, visited))
4. Return ans.
*/

class Solution {
private:
    double dfs(string u, string target, double currentProduct, unordered_set<string>& vis, unordered_map<string, vector<pair<string, double>>>& adj) {
        if (u == target) {
            return currentProduct;
        }

        vis.insert(u);

        for (auto& edge : adj[u]) {
            string v = edge.first;
            double weight = edge.second;

            if (vis.find(v) == vis.end()) {
                double res = dfs(v, target, currentProduct * weight, vis, adj);
                if (res != -1.0) {
                    return res;
                }
            }
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;

        // Build the graph
        for (int i = 0; i < (int)equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }

        vector<double> ans;

        for (auto& q : queries) {
            string src = q[0];
            string dst = q[1];

            if (adj.find(src) == adj.end() || adj.find(dst) == adj.end()) {
                ans.push_back(-1.0);
            } else {
                unordered_set<string> vis;
                ans.push_back(dfs(src, dst, 1.0, vis, adj));
            }
        }

        return ans;
    }
};
