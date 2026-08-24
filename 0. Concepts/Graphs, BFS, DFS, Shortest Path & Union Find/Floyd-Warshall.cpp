/*
 * ============================================================================
 * Concept: Floyd-Warshall (All-Pairs Shortest Path)
 * Subtopic: Graphs, BFS, DFS, Shortest Path & Union Find
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Dynamic programming algorithm computing shortest path distances between ALL pairs of vertices.
State transition: `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])` considering `k` as intermediate vertex.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(V^3) time complexity.
 * - Space Complexity: O(V^2) distance matrix space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - All-pairs shortest path for small V (V <= 400).
- Find the City With the Smallest Number of Neighbors at a Threshold Distance (LC 1334).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Floyd-Warshall Algorithm.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

void floydWarshall(int n, vector<vector<int>>& dist) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int n = 3;
    vector<vector<int>> dist = {
        {0, 4, INF},
        {INF, 0, 1},
        {2, INF, 0}
    };
    floydWarshall(n, dist);
    cout << "Dist 0->2: " << dist[0][2] << "\n"; // 0->1->2 = 5
    return 0;
}
