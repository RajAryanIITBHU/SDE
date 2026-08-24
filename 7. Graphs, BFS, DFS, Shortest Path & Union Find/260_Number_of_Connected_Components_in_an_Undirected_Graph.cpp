// Link: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Disjoint Set Union (DSU)
class DSU {
public:
    vector<int> parent;
    int components;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
            components--;
        }
    }
};

// ==========================================
// 1. OPTIMAL APPROACH (Disjoint Set Union - DSU)
// ==========================================
// Time Complexity  : O(V + E * alpha(V))
// Space Complexity : O(V)
/*
PSEUDOCODE:
1. Initialize DSU with n components.
2. For each edge (u, v) in edges:
     dsu.unite(u, v)
3. Return dsu.components.
*/

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for (auto& edge : edges) {
            dsu.unite(edge[0], edge[1]);
        }

        return dsu.components;
    }
};
