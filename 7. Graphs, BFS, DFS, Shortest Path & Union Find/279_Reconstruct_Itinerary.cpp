// Link: https://leetcode.com/problems/reconstruct-itinerary/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Hierholzer's Algorithm - Eulerian Path DFS)
// ==========================================
// Time Complexity  : O(E log E)
// Space Complexity : O(V + E)
/*
PSEUDOCODE:
1. Build adjacency list: adj[src] = min-heap priority_queue of destination strings.
2. Helper dfs(u, ans):
     While !adj[u].empty():
         nextDst = adj[u].top()
         adj[u].pop()
         dfs(nextDst, ans)
     ans.push_back(u) // Add to itinerary in postorder
3. dfs("JFK", ans).
4. Reverse ans and return.
*/

class Solution {
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;

    void dfs(string u, vector<string>& ans) {
        while (!adj[u].empty()) {
            string v = adj[u].top();
            adj[u].pop();
            dfs(v, ans);
        }
        ans.push_back(u); // Postorder push
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& t : tickets) {
            adj[t[0]].push(t[1]);
        }

        vector<string> ans;
        dfs("JFK", ans);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
