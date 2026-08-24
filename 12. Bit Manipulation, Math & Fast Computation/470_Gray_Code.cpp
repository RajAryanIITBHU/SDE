// Link: https://leetcode.com/problems/gray-code/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Direct Formula i ^ (i >> 1))
// ==========================================
// Time Complexity  : O(2^n)
// Space Complexity : O(1) auxiliary
/*
PSEUDOCODE:
Gray code formula for the i-th number:
  gray(i) = i ^ (i >> 1)
1. Initialize vector ans of size 2^n.
2. For i from 0 to (1 << n) - 1:
     ans.push_back(i ^ (i >> 1))
3. Return ans.
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        int total = 1 << n;
        vector<int> ans;
        ans.reserve(total);

        for (int i = 0; i < total; i++) {
            ans.push_back(i ^ (i >> 1));
        }

        return ans;
    }
};
