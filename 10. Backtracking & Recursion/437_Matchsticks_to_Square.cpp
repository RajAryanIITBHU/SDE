// Link: https://leetcode.com/problems/matchsticks-to-square/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with Descending Sort Pruning)
// ==========================================
// Time Complexity  : O(4^n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. totalLen = sum(matchsticks).
2. If totalLen % 4 != 0 || matchsticks.size() < 4 return false.
3. side = totalLen / 4.
4. Sort matchsticks in descending order (places longest sticks first to fail fast).
5. sides array of size 4 initialized to 0.
6. Helper backtrack(idx, matchsticks, sides, side):
     if idx == matchsticks.size():
         return sides[0] == side && sides[1] == side && sides[2] == side && sides[3] == side
     For i from 0 to 3:
         if sides[i] + matchsticks[idx] > side continue
         if i > 0 && sides[i] == sides[i - 1] continue // Deduplication of symmetric side states
         sides[i] += matchsticks[idx]
         if backtrack(idx + 1, matchsticks, sides, side) return true
         sides[i] -= matchsticks[idx] // Backtrack
     return false
7. Return backtrack(0, matchsticks, sides, side).
*/

class Solution {
private:
    bool backtrack(int idx, vector<int>& matchsticks, vector<int>& sides, int side) {
        if (idx == (int)matchsticks.size()) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[idx] > side) continue;

            // Pruning: skip identical empty/partial side configurations
            if (i > 0 && sides[i] == sides[i - 1]) continue;

            sides[i] += matchsticks[idx];
            if (backtrack(idx + 1, matchsticks, sides, side)) {
                return true;
            }
            sides[i] -= matchsticks[idx]; // Backtrack
        }

        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;

        int totalLen = 0;
        for (int m : matchsticks) totalLen += m;

        if (totalLen % 4 != 0) return false;
        int side = totalLen / 4;

        // Longest sticks first to fail early
        sort(matchsticks.rbegin(), matchsticks.rend());

        vector<int> sides(4, 0);
        return backtrack(0, matchsticks, sides, side);
    }
};
