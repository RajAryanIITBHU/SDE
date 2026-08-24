// Link: https://leetcode.com/problems/combination-sum/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with Candidate Reuse)
// ==========================================
// Time Complexity  : O(2^target * k)
// Space Complexity : O(target / min_candidate)
/*
PSEUDOCODE:
1. Sort candidates to prune branches early.
2. Helper backtrack(startIdx, target, currentComb, ans, candidates):
     if target == 0:
         ans.push_back(currentComb)
         return
     For i from startIdx to candidates.size() - 1:
         if candidates[i] > target break
         currentComb.push_back(candidates[i])
         backtrack(i, target - candidates[i], currentComb, ans, candidates) // Reusable i
         currentComb.pop_back() // Backtrack
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

            currentComb.push_back(candidates[i]);
            backtrack(i, target - candidates[i], currentComb, ans, candidates); // Same index i allows reuse
            currentComb.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> currentComb;

        backtrack(0, target, currentComb, ans, candidates);
        return ans;
    }
};
