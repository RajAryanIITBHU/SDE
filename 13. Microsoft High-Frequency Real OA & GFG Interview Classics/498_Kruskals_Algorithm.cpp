// Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Disjoint Set Union (DSU) with Path Compression & Union by Rank
class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);

        if (rootI != rootJ) {
            if (rank[rootI] < rank[rootJ]) {
                parent[rootI] = rootJ;
            } else if (rank[rootI] > rank[rootJ]) {
                parent[rootJ] = rootI;
            } else {
                parent[rootJ] = rootI;
                rank[rootI]++;
            }
            return true;
        }
        return false;
    }
};

// ==========================================
// 1. OPTIMAL APPROACH (Kruskal's Algorithm / Edge Sorting + DSU)
// ==========================================
// Time Complexity  : O(E log E)
// Space Complexity : O(V + E)
/*
PSEUDOCODE:
1. Extract all edges as {weight, u, v}.
2. Sort edges by weight in ascending order.
3. DSU dsu(V), mstWeight = 0, edgesCount = 0.
4. For each edge [wt, u, v]:
     if dsu.unite(u, v):
         mstWeight += wt
         edgesCount++
         if edgesCount == V - 1 break
5. Return mstWeight.
*/

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>> edges;

        for (int u = 0; u < V; u++) {
            for (auto& neighbor : adj[u]) {
                int v = neighbor[0];
                int wt = neighbor[1];
                if (u < v) { // Avoid duplicate undirected edges
                    edges.push_back({wt, u, v});
                }
            }
        }

        sort(edges.begin(), edges.end());

        DSU dsu(V);
        int mstWeight = 0;
        int count = 0;

        for (const auto& edge : edges) {
            int wt = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (dsu.unite(u, v)) {
                mstWeight += wt;
                count++;
                if (count == V - 1) break;
            }
        }

        return mstWeight;
    }
};
