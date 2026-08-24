// Link: https://leetcode.com/problems/combinations/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with Pruning)
// ==========================================
// Time Complexity  : O(C(n, k) * k)
// Space Complexity : O(k)
/*
PSEUDOCODE:
1. Helper backtrack(start, n, k, currentComb, ans):
     if currentComb.size() == k:
         ans.push_back(currentComb)
         return
     // Pruning: need (k - currentComb.size()) more elements
     For i from start to n - (k - currentComb.size()) + 1:
         currentComb.push_back(i)
         backtrack(i + 1, n, k, currentComb, ans)
         currentComb.pop_back()
2. backtrack(1, n, k, currentComb, ans).
3. Return ans.
*/

class Solution {
private:
    void backtrack(int start, int n, int k, vector<int>& currentComb, vector<vector<int>>& ans) {
        if ((int)currentComb.size() == k) {
            ans.push_back(currentComb);
            return;
        }

        int needed = k - currentComb.size();
        for (int i = start; i <= n - needed + 1; i++) {
            currentComb.push_back(i);
            backtrack(i + 1, n, k, currentComb, ans);
            currentComb.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> currentComb;
        backtrack(1, n, k, currentComb, ans);
        return ans;
    }
};
