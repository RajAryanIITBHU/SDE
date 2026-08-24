// Link: https://leetcode.com/problems/combination-sum-iii/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking 1..9 Digits)
// ==========================================
// Time Complexity  : O(C(9, k) * k)
// Space Complexity : O(k)
/*
PSEUDOCODE:
1. Helper backtrack(startDigit, k, target, currentComb, ans):
     if currentComb.size() == k && target == 0:
         ans.push_back(currentComb)
         return
     if currentComb.size() >= k || target < 0 return
     For d from startDigit to 9:
         if d > target break
         currentComb.push_back(d)
         backtrack(d + 1, k, target - d, currentComb, ans)
         currentComb.pop_back()
2. backtrack(1, k, n, currentComb, ans).
3. Return ans.
*/

class Solution {
private:
    void backtrack(int startDigit, int k, int target, vector<int>& currentComb, vector<vector<int>>& ans) {
        if ((int)currentComb.size() == k && target == 0) {
            ans.push_back(currentComb);
            return;
        }

        if ((int)currentComb.size() >= k || target < 0) {
            return;
        }

        for (int d = startDigit; d <= 9; d++) {
            if (d > target) break; // Pruning

            currentComb.push_back(d);
            backtrack(d + 1, k, target - d, currentComb, ans);
            currentComb.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> currentComb;
        backtrack(1, k, n, currentComb, ans);
        return ans;
    }
};
