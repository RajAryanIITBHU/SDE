// Link: https://leetcode.com/problems/graph-valid-tree/

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

    bool unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI == rootJ) return false; // Cycle detected

        parent[rootI] = rootJ;
        components--;
        return true;
    }
};

// ==========================================
// 1. OPTIMAL APPROACH (Union-Find Cycle Detection & Components Check)
// ==========================================
// Time Complexity  : O(E * alpha(V))
// Space Complexity : O(V)
/*
PSEUDOCODE:
A valid tree must have:
1. Exactly n - 1 edges.
2. Exactly 1 connected component (no cycles).
If edges.size() != n - 1 return false.
For each edge (u, v):
     if !dsu.unite(u, v) -> return false (cycle exists)
Return dsu.components == 1.
*/

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if ((int)edges.size() != n - 1) {
            return false;
        }

        DSU dsu(n);

        for (auto& edge : edges) {
            if (!dsu.unite(edge[0], edge[1])) {
                return false; // Cycle found
            }
        }

        return dsu.components == 1;
    }
};
