// Link: https://leetcode.com/problems/number-of-flowers-in-full-bloom/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Sorted Start & End Times)
// ==========================================
// Time Complexity  : O((n + m) * log n), where n = flowers.size(), m = people.size()
// Space Complexity : O(n)
/*
PSEUDOCODE:
Flowers blooming at time t = (flowers started <= t) - (flowers ended < t).
1. Extract start times and end times into separate arrays starts and ends.
2. Sort starts and ends independently.
3. For each person at time t:
     bloomed = upper_bound(starts, t) - starts.begin()
     expired = lower_bound(ends, t) - ends.begin()
     ans.push_back(bloomed - expired)
4. Return ans.
*/

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        vector<int> starts(n);
        vector<int> ends(n);

        for (int i = 0; i < n; i++) {
            starts[i] = flowers[i][0];
            ends[i] = flowers[i][1];
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        vector<int> ans;

        for (int t : people) {
            // Flowers that have already started blooming by time t
            int bloomed = upper_bound(starts.begin(), starts.end(), t) - starts.begin();
            // Flowers that have finished blooming before time t
            int expired = lower_bound(ends.begin(), ends.end(), t) - ends.begin();

            ans.push_back(bloomed - expired);
        }

        return ans;
    }
};
