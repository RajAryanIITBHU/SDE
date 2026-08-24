// Link: https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/

#include <iostream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Triangular Numbers Math / Analytical Solution)
// ==========================================
// Time Complexity  : O(sqrt(n)) or O(1)
// Space Complexity : O(1)
/*
PSEUDOCODE:
With 2 eggs, if we take x moves, the max floors we can test is:
  x + (x - 1) + (x - 2) + ... + 1 = x * (x + 1) / 2
We need the smallest integer x such that:
  x * (x + 1) / 2 >= n
1. moves = 0.
2. While n > 0:
     moves++
     n -= moves
3. Return moves.
*/

class Solution {
public:
    int twoEggDrop(int n) {
        int moves = 0;

        while (n > 0) {
            moves++;
            n -= moves;
        }

        return moves;
    }
};
