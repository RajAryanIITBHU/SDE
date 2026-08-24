// Link: https://leetcode.com/problems/redundant-connection/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Disjoint Set Union (DSU)
class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI == rootJ) return false; // Cycle detected

        parent[rootI] = rootJ;
        return true;
    }
};

// ==========================================
// 1. OPTIMAL APPROACH (Union-Find Cycle Detection)
// ==========================================
// Time Complexity  : O(n * alpha(n))
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize DSU for n nodes.
2. For each edge (u, v) in edges:
     if !dsu.unite(u, v) -> return edge (creates cycle, is redundant)
3. Return {}.
*/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for (auto& edge : edges) {
            if (!dsu.unite(edge[0], edge[1])) {
                return edge;
            }
        }

        return {};
    }
};
