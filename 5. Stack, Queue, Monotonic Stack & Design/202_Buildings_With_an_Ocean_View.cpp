// Link: https://leetcode.com/problems/buildings-with-an-ocean-view/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Right-to-Left Max Height Scan)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. Initialize maxHeight = 0, vector<int> ans.
2. Loop from n - 1 down to 0:
     if heights[i] > maxHeight:
         ans.push_back(i)
         maxHeight = heights[i]
3. Reverse ans (to restore ascending index order) and return.
*/

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans;
        int maxHeight = 0;

        // Traverse right to left towards the ocean
        for (int i = n - 1; i >= 0; i--) {
            if (heights[i] > maxHeight) {
                ans.push_back(i);
                maxHeight = heights[i];
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
