// Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/

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
// 1. OPTIMAL APPROACH (Union-Find Components Count)
// ==========================================
// Time Complexity  : O(n + connections.size() * alpha(n))
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. To connect n computers, at least n - 1 cables are needed.
2. If connections.size() < n - 1 return -1.
3. Initialize DSU with n components.
4. For each (u, v) in connections:
     dsu.unite(u, v)
5. Cables needed to connect all components = dsu.components - 1.
6. Return dsu.components - 1.
*/

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Need at least n - 1 cables to connect n nodes
        if ((int)connections.size() < n - 1) {
            return -1;
        }

        DSU dsu(n);

        for (auto& conn : connections) {
            dsu.unite(conn[0], conn[1]);
        }

        return dsu.components - 1;
    }
};
