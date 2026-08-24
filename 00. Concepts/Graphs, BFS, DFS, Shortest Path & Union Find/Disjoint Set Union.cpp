/*
 * ============================================================================
 * Concept: Disjoint Set Union (DSU / Union-Find)
 * Subtopic: Graphs, BFS, DFS, Shortest Path & Union Find
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Data structure managing a set of partitioned elements into disjoint subsets.
Optimizations:
1. Path Compression: `find(i) = parent[i] = find(parent[i])` flattens tree structure to O(1) amortized.
2. Union by Rank/Size: Attach smaller tree under root of larger tree.
Amortized time complexity: `O(alpha(N))` per operation (nearly constant time).
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(alpha(N)) ~ O(1) amortized per operation.
 * - Space Complexity: O(N) parent and rank/size array space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Number of Connected Components (LC 323).
- Redundant Connection (LC 684).
- Accounts Merge (LC 721).
- Kruskal's MST algorithm.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. DSU implementation with Path Compression & Rank Optimization.
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }
    
    bool unite(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            if (rank[root_i] == rank[root_j]) rank[root_i]++;
            return true;
        }
        return false; // Already in same set
    }
};

int main() {
    DSU dsu(5);
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    cout << "0 and 2 connected: " << (dsu.find(0) == dsu.find(2) ? "Yes" : "No") << "\n";
    return 0;
}
