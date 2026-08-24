// Link: https://leetcode.com/problems/permutations-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with Visited Tracking & Duplicate Skipping)
// ==========================================
// Time Complexity  : O(n * n!)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Sort nums.
2. Maintain used boolean array of size n.
3. Helper backtrack(currentPerm, ans, nums, used):
     if currentPerm.size() == nums.size():
         ans.push_back(currentPerm)
         return
     For i from 0 to nums.size() - 1:
         if used[i] continue
         if i > 0 && nums[i] == nums[i - 1] && !used[i - 1] continue // Skip duplicate
         used[i] = true
         currentPerm.push_back(nums[i])
         backtrack(currentPerm, ans, nums, used)
         currentPerm.pop_back()
         used[i] = false
4. Return ans.
*/

class Solution {
private:
    void backtrack(vector<int>& currentPerm, vector<vector<int>>& ans, vector<int>& nums, vector<bool>& used) {
        if (currentPerm.size() == nums.size()) {
            ans.push_back(currentPerm);
            return;
        }

        for (int i = 0; i < (int)nums.size(); i++) {
            if (used[i]) continue;

            // When duplicate value encountered, only proceed if previous identical element was already chosen
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            used[i] = true;
            currentPerm.push_back(nums[i]);

            backtrack(currentPerm, ans, nums, used);

            currentPerm.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> currentPerm;
        vector<bool> used(nums.size(), false);

        backtrack(currentPerm, ans, nums, used);
        return ans;
    }
};
