// Link: https://leetcode.com/problems/sum-of-all-subset-xor-totals/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Bitwise Math OR Reduction)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
Mathematical Property:
Every bit that appears in at least one element of nums will be set in exactly half of all 2^n subsets.
Therefore, total XOR sum = (OR of all elements) * 2^(n - 1).
1. totalOR = 0.
2. For each num in nums: totalOR |= num.
3. Return totalOR << (nums.size() - 1).
*/

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int totalOR = 0;
        for (int num : nums) {
            totalOR |= num;
        }

        // Each set bit appears in exactly 2^(n-1) subsets
        return totalOR << (nums.size() - 1);
    }
};
