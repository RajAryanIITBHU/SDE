// Link: https://leetcode.com/problems/satisfiability-of-equality-equations/

#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

// Disjoint Set Union (DSU)
class DSU {
public:
    vector<int> parent;

    DSU() {
        parent.resize(26);
        iota(parent.begin(), parent.end(), 0);
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
        }
    }
};

// ==========================================
// 1. OPTIMAL APPROACH (2-Pass Union-Find on 26 Lowercase Letters)
// ==========================================
// Time Complexity  : O(n * alpha(26)) = O(n)
// Space Complexity : O(1) (26 characters)
/*
PSEUDOCODE:
1. Initialize DSU for 26 lowercase English letters.
2. Pass 1: For each equation with "==" (e.g. "a==b"):
     dsu.unite(eq[0] - 'a', eq[3] - 'a')
3. Pass 2: For each equation with "!=" (e.g. "a!=b"):
     if dsu.find(eq[0] - 'a') == dsu.find(eq[3] - 'a') -> return false (contradiction!)
4. Return true.
*/

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu;

        // Pass 1: Group variables connected by '=='
        for (string& eq : equations) {
            if (eq[1] == '=') {
                dsu.unite(eq[0] - 'a', eq[3] - 'a');
            }
        }

        // Pass 2: Verify inequalities '!='
        for (string& eq : equations) {
            if (eq[1] == '!') {
                if (dsu.find(eq[0] - 'a') == dsu.find(eq[3] - 'a')) {
                    return false; // Contradiction
                }
            }
        }

        return true;
    }
};
