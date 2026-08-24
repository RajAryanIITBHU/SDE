// Link: https://leetcode.com/problems/number-of-provinces/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (DFS Connected Components)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize vis vector of size n with false.
2. Helper dfs(u):
     vis[u] = true
     For v from 0 to n-1:
         if isConnected[u][v] == 1 && !vis[v]:
             dfs(v)
3. provinces = 0.
4. For i from 0 to n-1:
     if !vis[i]:
         provinces++
         dfs(i)
5. Return provinces.
*/

class Solution {
private:
    void dfs(int u, vector<bool>& vis, vector<vector<int>>& isConnected, int n) {
        vis[u] = true;

        for (int v = 0; v < n; v++) {
            if (isConnected[u][v] == 1 && !vis[v]) {
                dfs(v, vis, isConnected, n);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                provinces++;
                dfs(i, vis, isConnected, n);
            }
        }

        return provinces;
    }
};
