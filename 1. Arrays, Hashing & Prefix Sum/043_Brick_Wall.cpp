// Link: https://leetcode.com/problems/brick-wall/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Prefix Sum Edges + Hash Map)
// ==========================================
// Time Complexity  : O(total_bricks)
// Space Complexity : O(total_unique_edge_positions)
/*
PSEUDOCODE:
1. Create hash map mp: edgePosition -> count.
2. maxEdges = 0.
3. For each row in wall:
     edge = 0
     For j from 0 to row.size() - 2 (ignore the rightmost edge of wall):
         edge += row[j]
         mp[edge]++
         maxEdges = max(maxEdges, mp[edge])
4. Least crossed bricks = wall.size() - maxEdges.
5. Return wall.size() - maxEdges.
*/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<int, int> mp; // {edgePosition, count}
        int maxEdges = 0;

        for (int i = 0; i < n; i++) {
            int edge = 0;
            // Iterate up to row.size() - 1 to ignore the final edge of the wall
            for (int j = 0; j < (int)wall[i].size() - 1; j++) {
                edge += wall[i][j];
                mp[edge]++;
                maxEdges = max(maxEdges, mp[edge]);
            }
        }

        // Total rows minus the maximum number of aligned edges
        return n - maxEdges;
    }
};
