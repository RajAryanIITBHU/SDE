// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Two Pointers)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize left = 0, right = n - 1 (1-indexed output requires adding 1).
2. While left < right:
     sum = numbers[left] + numbers[right]
     if sum == target -> return {left + 1, right + 1}
     else if sum < target -> left++
     else -> right--
3. Return {}
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = (int)numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1}; // 1-indexed
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};
    }
};
