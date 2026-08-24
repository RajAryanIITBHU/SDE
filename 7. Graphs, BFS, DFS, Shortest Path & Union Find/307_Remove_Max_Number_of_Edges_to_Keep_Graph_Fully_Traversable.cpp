// Link: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

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
        parent.resize(n + 1);
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
        if (rootI == rootJ) return false;

        parent[rootI] = rootJ;
        components--;
        return true;
    }

    bool isConnected() {
        return components == 1;
    }
};

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Common Type-3 Edges First + Dual DSU)
// ==========================================
// Time Complexity  : O(E * alpha(V))
// Space Complexity : O(V)
/*
PSEUDOCODE:
1. Maintain aliceDSU and bobDSU.
2. usedEdges = 0.
3. Pass 1 (Type 3 - Common):
     For each edge with type == 3:
         if aliceDSU.unite(u, v):
             bobDSU.unite(u, v)
             usedEdges++
4. Pass 2 (Type 1 - Alice Only & Type 2 - Bob Only):
     For each edge:
         if type == 1 && aliceDSU.unite(u, v) -> usedEdges++
         if type == 2 && bobDSU.unite(u, v) -> usedEdges++
5. If aliceDSU.isConnected() && bobDSU.isConnected():
     return edges.size() - usedEdges
6. Return -1.
*/

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);

        int usedEdges = 0;

        // Step 1: Process Type 3 (Both Alice & Bob can use)
        for (auto& edge : edges) {
            if (edge[0] == 3) {
                bool uA = alice.unite(edge[1], edge[2]);
                bool uB = bob.unite(edge[1], edge[2]);
                if (uA || uB) {
                    usedEdges++;
                }
            }
        }

        // Step 2: Process Type 1 (Alice) and Type 2 (Bob)
        for (auto& edge : edges) {
            if (edge[0] == 1) {
                if (alice.unite(edge[1], edge[2])) {
                    usedEdges++;
                }
            } else if (edge[0] == 2) {
                if (bob.unite(edge[1], edge[2])) {
                    usedEdges++;
                }
            }
        }

        if (alice.isConnected() && bob.isConnected()) {
            return (int)edges.size() - usedEdges;
        }

        return -1;
    }
};
