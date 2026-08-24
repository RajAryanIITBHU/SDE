// Link: https://leetcode.com/problems/counting-bits/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D Bitwise Dynamic Programming)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) auxiliary
/*
PSEUDOCODE:
Recurrence:
  Number of set bits in i = (set bits in i >> 1) + (i & 1)
1. Initialize ans array of size n + 1 with 0.
2. For i from 1 to n:
     ans[i] = ans[i >> 1] + (i & 1)
3. Return ans.
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};
