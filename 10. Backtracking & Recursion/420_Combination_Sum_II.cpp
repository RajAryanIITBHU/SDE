// Link: https://leetcode.com/problems/combination-sum-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with Duplicate Skipping)
// ==========================================
// Time Complexity  : O(2^n * n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Sort candidates.
2. Helper backtrack(startIdx, target, currentComb, ans, candidates):
     if target == 0:
         ans.push_back(currentComb)
         return
     For i from startIdx to candidates.size() - 1:
         if candidates[i] > target break
         if i > startIdx && candidates[i] == candidates[i - 1] continue // Skip duplicates
         currentComb.push_back(candidates[i])
         backtrack(i + 1, target - candidates[i], currentComb, ans, candidates)
         currentComb.pop_back()
3. backtrack(0, target, currentComb, ans, candidates).
4. Return ans.
*/

class Solution {
private:
    void backtrack(int startIdx, int target, vector<int>& currentComb, vector<vector<int>>& ans, vector<int>& candidates) {
        if (target == 0) {
            ans.push_back(currentComb);
            return;
        }

        for (int i = startIdx; i < (int)candidates.size(); i++) {
            if (candidates[i] > target) break; // Pruning

            // Skip duplicate values in the same recursion level
            if (i > startIdx && candidates[i] == candidates[i - 1]) {
                continue;
            }

            currentComb.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], currentComb, ans, candidates);
            currentComb.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> currentComb;

        backtrack(0, target, currentComb, ans, candidates);
        return ans;
    }
};
