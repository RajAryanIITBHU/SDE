// Link: https://leetcode.com/problems/subsets/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking Power Set Generation)
// ==========================================
// Time Complexity  : O(n * 2^n)
// Space Complexity : O(n) recursion stack
/*
PSEUDOCODE:
1. Helper backtrack(startIdx, nums, currentSubset, ans):
     ans.push_back(currentSubset)
     For i from startIdx to nums.size() - 1:
         currentSubset.push_back(nums[i])
         backtrack(i + 1, nums, currentSubset, ans)
         currentSubset.pop_back()
2. backtrack(0, nums, currentSubset, ans).
3. Return ans.
*/

class Solution {
private:
    void backtrack(int startIdx, vector<int>& nums, vector<int>& currentSubset, vector<vector<int>>& ans) {
        ans.push_back(currentSubset);

        for (int i = startIdx; i < (int)nums.size(); i++) {
            currentSubset.push_back(nums[i]);
            backtrack(i + 1, nums, currentSubset, ans);
            currentSubset.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currentSubset;
        backtrack(0, nums, currentSubset, ans);
        return ans;
    }
};
