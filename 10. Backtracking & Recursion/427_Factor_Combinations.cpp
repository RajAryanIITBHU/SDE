// Link: https://leetcode.com/problems/factor-combinations/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with Minimum Factor)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(log n)
/*
PSEUDOCODE:
1. Helper backtrack(n, minFactor, currentComb, ans):
     if !currentComb.empty():
         currentComb.push_back(n)
         ans.push_back(currentComb)
         currentComb.pop_back()
     For factor from minFactor such that factor * factor <= n:
         if n % factor == 0:
             currentComb.push_back(factor)
             backtrack(n / factor, factor, currentComb, ans)
             currentComb.pop_back()
2. backtrack(n, 2, currentComb, ans).
3. Return ans.
*/

class Solution {
private:
    void backtrack(int n, int minFactor, vector<int>& currentComb, vector<vector<int>>& ans) {
        if (!currentComb.empty()) {
            currentComb.push_back(n);
            ans.push_back(currentComb);
            currentComb.pop_back();
        }

        for (int factor = minFactor; factor * factor <= n; factor++) {
            if (n % factor == 0) {
                currentComb.push_back(factor);
                backtrack(n / factor, factor, currentComb, ans);
                currentComb.pop_back(); // Backtrack
            }
        }
    }

public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> currentComb;
        backtrack(n, 2, currentComb, ans);
        return ans;
    }
};
