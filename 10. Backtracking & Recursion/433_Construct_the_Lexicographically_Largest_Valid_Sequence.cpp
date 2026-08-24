// Link: https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Largest Number First Backtracking)
// ==========================================
// Time Complexity  : O(n!)
// Space Complexity : O(n)
/*
PSEUDOCODE:
Sequence length = 2 * n - 1.
1. Initialize res of size 2*n - 1 with 0, used array of size n + 1 with false.
2. Helper backtrack(idx, n, res, used):
     if idx == res.size() return true
     if res[idx] != 0 return backtrack(idx + 1, n, res, used)
     // Try placing numbers from n down to 1
     For num from n down to 1:
         if used[num] continue
         if num == 1:
             res[idx] = 1, used[1] = true
             if backtrack(idx + 1, n, res, used) return true
             res[idx] = 0, used[1] = false
         else if idx + num < res.size() && res[idx + num] == 0:
             res[idx] = res[idx + num] = num
             used[num] = true
             if backtrack(idx + 1, n, res, used) return true
             res[idx] = res[idx + num] = 0
             used[num] = false
     return false
3. backtrack(0, n, res, used).
4. Return res.
*/

class Solution {
private:
    bool backtrack(int idx, int n, vector<int>& res, vector<bool>& used) {
        if (idx == (int)res.size()) {
            return true;
        }

        if (res[idx] != 0) {
            return backtrack(idx + 1, n, res, used);
        }

        // Try placing from largest integer n down to 1
        for (int num = n; num >= 1; num--) {
            if (used[num]) continue;

            if (num == 1) {
                res[idx] = 1;
                used[1] = true;

                if (backtrack(idx + 1, n, res, used)) return true;

                res[idx] = 0;
                used[1] = false;
            } else if (idx + num < (int)res.size() && res[idx + num] == 0) {
                res[idx] = res[idx + num] = num;
                used[num] = true;

                if (backtrack(idx + 1, n, res, used)) return true;

                res[idx] = res[idx + num] = 0;
                used[num] = false;
            }
        }

        return false;
    }

public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2 * n - 1, 0);
        vector<bool> used(n + 1, false);

        backtrack(0, n, res, used);
        return res;
    }
};
