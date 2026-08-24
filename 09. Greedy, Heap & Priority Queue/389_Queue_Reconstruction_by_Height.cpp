// Link: https://leetcode.com/problems/queue-reconstruction-by-height/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Sort + List Insertion)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Sort people by:
     - Height h in descending order
     - If heights are equal, by k in ascending order
2. Initialize vector<vector<int>> ans.
3. For each person in people:
     ans.insert(ans.begin() + person[1], person)
4. Return ans.
*/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort tall people first; for equal heights, sort smaller k first
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });

        vector<vector<int>> ans;

        for (const auto& p : people) {
            ans.insert(ans.begin() + p[1], p);
        }

        return ans;
    }
};
