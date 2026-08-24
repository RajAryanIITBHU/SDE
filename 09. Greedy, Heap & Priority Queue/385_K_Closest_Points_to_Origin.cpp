// Link: https://leetcode.com/problems/k-closest-points-to-origin/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Max-Heap of Size K)
// ==========================================
// Time Complexity  : O(n log k)
// Space Complexity : O(k)
/*
PSEUDOCODE:
1. Max-heap pq storing {distSq, {x, y}}.
2. For each pt in points:
     distSq = pt[0]*pt[0] + pt[1]*pt[1]
     pq.push({distSq, {pt[0], pt[1]}})
     if pq.size() > k:
         pq.pop()
3. Collect all points from pq into ans.
4. Return ans.
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max-heap: {distanceSquared, {x, y}}
        priority_queue<pair<int, pair<int, int>>> pq;

        for (auto& pt : points) {
            int distSq = pt[0] * pt[0] + pt[1] * pt[1];
            pq.push({distSq, {pt[0], pt[1]}});

            if ((int)pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto topPt = pq.top().second;
            ans.push_back({topPt.first, topPt.second});
            pq.pop();
        }

        return ans;
    }
};
