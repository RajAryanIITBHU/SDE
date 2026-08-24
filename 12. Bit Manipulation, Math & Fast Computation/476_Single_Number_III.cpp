// Link: https://leetcode.com/problems/single-number-iii/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Bitwise XOR + Lowest Set Bit Partitioning)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
Let the two unique numbers be a and b.
1. totalXOR = a ^ b.
2. Find lowest set bit in totalXOR: diffBit = totalXOR & (-totalXOR).
3. Partition numbers into two groups based on whether diffBit is set:
     - Group 1 (diffBit is 1): XOR to get a
     - Group 2 (diffBit is 0): XOR to get b
4. Return {num1, num2}.
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long totalXOR = 0;
        for (int num : nums) {
            totalXOR ^= num;
        }

        // Lowest set bit
        long long diffBit = totalXOR & (-totalXOR);

        int num1 = 0;
        int num2 = 0;

        for (int num : nums) {
            if (num & diffBit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }

        return {num1, num2};
    }
};
