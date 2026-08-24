// Link: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Kosaraju's 3-Step Algorithm)
// ==========================================
// Time Complexity  : O(V + E)
// Space Complexity : O(V + E)
/*
PSEUDOCODE:
1. Step 1: DFS on original graph to fill stack by finishing times.
2. Step 2: Transpose (reverse all edges) of graph.
3. Step 3: Pop from stack and perform DFS on transposed graph.
4. Count of DFS calls in Step 3 equals number of Strongly Connected Components (SCC).
*/

class Solution {
private:
    void dfs1(int u, const vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs1(v, adj, vis, st);
            }
        }
        st.push(u);
    }

    void dfs2(int u, const vector<vector<int>>& adjRev, vector<bool>& vis) {
        vis[u] = true;
        for (int v : adjRev[u]) {
            if (!vis[v]) {
                dfs2(v, adjRev, vis);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>>& adj) {
        vector<bool> vis(V, false);
        stack<int> st;

        // Step 1: Sort nodes according to finishing time
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs1(i, adj, vis, st);
            }
        }

        // Step 2: Reverse graph
        vector<vector<int>> adjRev(V);
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                adjRev[v].push_back(u);
            }
        }

        // Step 3: DFS according to finishing time on transposed graph
        fill(vis.begin(), vis.end(), false);
        int sccCount = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            if (!vis[u]) {
                sccCount++;
                dfs2(u, adjRev, vis);
            }
        }

        return sccCount;
    }
};
