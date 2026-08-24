// Link: https://leetcode.com/problems/the-skyline-problem/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sweep-Line with Multiset)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Deconstruct each building [L, R, H] into 2 events:
     Start event: {L, -H} (negative height distinguishes start and ensures tallest start processed first)
     End event: {R, H}
2. Sort events by x coordinate.
3. Multiset activeHeights initialized with {0}.
4. prevMaxHeight = 0, vector<vector<int>> ans.
5. For each event {x, h}:
     if h < 0:
         activeHeights.insert(-h) // Start of building
     else:
         activeHeights.erase(activeHeights.find(h)) // End of building
     currMaxHeight = *activeHeights.rbegin()
     if currMaxHeight != prevMaxHeight:
         ans.push_back({x, currMaxHeight})
         prevMaxHeight = currMaxHeight
6. Return ans.
*/

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;

        for (const auto& b : buildings) {
            events.push_back({b[0], -b[2]}); // Start event (negative height)
            events.push_back({b[1], b[2]});  // End event (positive height)
        }

        sort(events.begin(), events.end());

        multiset<int> activeHeights;
        activeHeights.insert(0); // Ground level height

        int prevMaxHeight = 0;
        vector<vector<int>> ans;

        for (const auto& ev : events) {
            int x = ev.first;
            int h = ev.second;

            if (h < 0) {
                activeHeights.insert(-h);
            } else {
                activeHeights.erase(activeHeights.find(h));
            }

            int currMaxHeight = *activeHeights.rbegin();
            if (currMaxHeight != prevMaxHeight) {
                ans.push_back({x, currMaxHeight});
                prevMaxHeight = currMaxHeight;
            }
        }

        return ans;
    }
};
