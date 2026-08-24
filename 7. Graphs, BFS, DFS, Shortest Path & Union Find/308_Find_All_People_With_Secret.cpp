// Link: https://leetcode.com/problems/find-all-people-with-secret/

#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;

// Disjoint Set Union (DSU)
class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
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

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void reset(int i) {
        parent[i] = i;
    }
};

// ==========================================
// 1. OPTIMAL APPROACH (Group by Time + DSU with Disconnect Reset)
// ==========================================
// Time Complexity  : O(M log M + M * alpha(N)), where M is meetings count
// Space Complexity : O(N + M)
/*
PSEUDOCODE:
1. Initialize DSU for n people.
2. dsu.unite(0, firstPerson).
3. Group meetings by timestamp t: timeMap[t] = list of meetings.
4. For each time t:
     For each meeting (x, y) at time t:
         dsu.unite(x, y)
     // Reset people at time t who did not connect to Person 0
     For each meeting (x, y) at time t:
         if !dsu.connected(x, 0):
             dsu.reset(x)
             dsu.reset(y)
5. Collect all people where dsu.connected(i, 0).
6. Return ans.
*/

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        DSU dsu(n);
        dsu.unite(0, firstPerson);

        // Group meetings by timestamp
        map<int, vector<pair<int, int>>> timeMap;
        for (auto& m : meetings) {
            timeMap[m[2]].push_back({m[0], m[1]});
        }

        for (auto& p : timeMap) {
            auto& meetList = p.second;

            // Connect people meeting at this timestamp
            for (auto& meet : meetList) {
                dsu.unite(meet.first, meet.second);
            }

            // Disconnect people who did not receive the secret from 0
            for (auto& meet : meetList) {
                if (!dsu.connected(meet.first, 0)) {
                    dsu.reset(meet.first);
                    dsu.reset(meet.second);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dsu.connected(i, 0)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
