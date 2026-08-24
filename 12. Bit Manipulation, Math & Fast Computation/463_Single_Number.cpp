// Link: https://leetcode.com/problems/single-number/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Bitwise XOR Accumulation)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
XOR Property: a ^ a = 0 and a ^ 0 = a.
1. ans = 0.
2. For each num in nums:
     ans ^= num
3. Return ans.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
};
