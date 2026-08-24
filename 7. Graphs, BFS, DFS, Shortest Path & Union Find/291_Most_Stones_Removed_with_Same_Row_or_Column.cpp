// Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Disjoint Set Union (DSU) using Hash Map for coordinate compression
class DSU {
public:
    unordered_map<int, int> parent;
    int components = 0;

    int find(int i) {
        if (parent.find(i) == parent.end()) {
            parent[i] = i;
            components++;
        }
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
// 1. OPTIMAL APPROACH (Union-Find on Rows and Columns)
// ==========================================
// Time Complexity  : O(n * alpha(n))
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Represent rows as r, and columns as ~c (bitwise NOT to differentiate column namespace).
2. For each stone (r, c):
     dsu.unite(r, ~c)
3. Max stones removed = totalStones - connectedComponentsCount.
4. Return stones.size() - dsu.components.
*/

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;

        for (auto& stone : stones) {
            int r = stone[0];
            int c = ~stone[1]; // Differentiate row coordinate from column coordinate
            dsu.unite(r, c);
        }

        return stones.size() - dsu.components;
    }
};
