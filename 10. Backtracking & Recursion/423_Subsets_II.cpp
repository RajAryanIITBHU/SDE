// Link: https://leetcode.com/problems/subsets-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with Sorting & Duplicate Skipping)
// ==========================================
// Time Complexity  : O(n * 2^n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Sort nums.
2. Helper backtrack(startIdx, nums, currentSubset, ans):
     ans.push_back(currentSubset)
     For i from startIdx to nums.size() - 1:
         if i > startIdx && nums[i] == nums[i - 1] continue // Skip duplicate elements
         currentSubset.push_back(nums[i])
         backtrack(i + 1, nums, currentSubset, ans)
         currentSubset.pop_back()
3. backtrack(0, nums, currentSubset, ans).
4. Return ans.
*/

class Solution {
private:
    void backtrack(int startIdx, vector<int>& nums, vector<int>& currentSubset, vector<vector<int>>& ans) {
        ans.push_back(currentSubset);

        for (int i = startIdx; i < (int)nums.size(); i++) {
            // Skip duplicate values in current recursive depth
            if (i > startIdx && nums[i] == nums[i - 1]) {
                continue;
            }

            currentSubset.push_back(nums[i]);
            backtrack(i + 1, nums, currentSubset, ans);
            currentSubset.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> currentSubset;

        backtrack(0, nums, currentSubset, ans);
        return ans;
    }
};
