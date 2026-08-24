// Link: https://leetcode.com/problems/single-number-ii/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Bit Counter / Digital Logic State Machine)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
State machine for modulo 3 counter:
  ones = (ones ^ num) & ~twos
  twos = (twos ^ num) & ~ones
1. ones = 0, twos = 0.
2. For each num in nums:
     ones = (ones ^ num) & ~twos
     twos = (twos ^ num) & ~ones
3. Return ones.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;

        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }

        return ones;
    }
};
