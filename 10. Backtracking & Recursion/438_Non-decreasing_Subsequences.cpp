// Link: https://leetcode.com/problems/non-decreasing-subsequences/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with Local Hash Set for Deduplication)
// ==========================================
// Time Complexity  : O(2^n * n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Helper backtrack(startIdx, nums, currentSeq, ans):
     if currentSeq.size() >= 2:
         ans.push_back(currentSeq)
     unordered_set<int> usedInThisLevel // Deduplicates identical choices at same depth
     For i from startIdx to nums.size() - 1:
         if (!currentSeq.empty() && nums[i] < currentSeq.back()) continue
         if usedInThisLevel.count(nums[i]) continue
         usedInThisLevel.insert(nums[i])
         currentSeq.push_back(nums[i])
         backtrack(i + 1, nums, currentSeq, ans)
         currentSeq.pop_back()
2. backtrack(0, nums, currentSeq, ans).
3. Return ans.
*/

class Solution {
private:
    void backtrack(int startIdx, vector<int>& nums, vector<int>& currentSeq, vector<vector<int>>& ans) {
        if (currentSeq.size() >= 2) {
            ans.push_back(currentSeq);
        }

        unordered_set<int> usedInLevel;

        for (int i = startIdx; i < (int)nums.size(); i++) {
            if (!currentSeq.empty() && nums[i] < currentSeq.back()) {
                continue;
            }

            if (usedInLevel.find(nums[i]) != usedInLevel.end()) {
                continue;
            }

            usedInLevel.insert(nums[i]);
            currentSeq.push_back(nums[i]);

            backtrack(i + 1, nums, currentSeq, ans);

            currentSeq.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currentSeq;
        backtrack(0, nums, currentSeq, ans);
        return ans;
    }
};
