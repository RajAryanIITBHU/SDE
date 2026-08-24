// Link: https://leetcode.com/problems/total-hamming-distance/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Bit Position Counting)
// ==========================================
// Time Complexity  : O(32 * n) = O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
For each bit position i (from 0 to 31):
  Let k = count of numbers with i-th bit set.
  Number of pairs differing at bit i = k * (n - k).
1. totalDist = 0, n = nums.size().
2. For i from 0 to 31:
     setCount = 0
     For each num in nums:
         if (num >> i) & 1: setCount++
     totalDist += setCount * (n - setCount)
3. Return totalDist.
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int totalDistance = 0;
        int n = nums.size();

        for (int i = 0; i < 32; i++) {
            int countOnes = 0;
            for (int num : nums) {
                if ((num >> i) & 1) {
                    countOnes++;
                }
            }
            totalDistance += countOnes * (n - countOnes);
        }

        return totalDistance;
    }
};
