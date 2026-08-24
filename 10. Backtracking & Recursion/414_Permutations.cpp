// Link: https://leetcode.com/problems/permutations/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (In-Place Swapping Backtracking)
// ==========================================
// Time Complexity  : O(n * n!)
// Space Complexity : O(n) recursion stack
/*
PSEUDOCODE:
1. Helper backtrack(startIdx, nums, ans):
     if startIdx == nums.size():
         ans.push_back(nums)
         return
     For i from startIdx to nums.size() - 1:
         swap(nums[startIdx], nums[i])
         backtrack(startIdx + 1, nums, ans)
         swap(nums[startIdx], nums[i]) // Backtrack
2. backtrack(0, nums, ans).
3. Return ans.
*/

class Solution {
private:
    void backtrack(int startIdx, vector<int>& nums, vector<vector<int>>& ans) {
        if (startIdx == (int)nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = startIdx; i < (int)nums.size(); i++) {
            swap(nums[startIdx], nums[i]);
            backtrack(startIdx + 1, nums, ans);
            swap(nums[startIdx], nums[i]); // Backtrack
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(0, nums, ans);
        return ans;
    }
};
