// Link: https://leetcode.com/problems/3sum-closest/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sorting + Two Pointers)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Sort nums: sort(nums.begin(), nums.end()).
2. Initialize closestSum = nums[0] + nums[1] + nums[2].
3. For i from 0 to n-3:
     left = i + 1, right = n - 1
     While left < right:
         currentSum = nums[i] + nums[left] + nums[right]
         if abs(currentSum - target) < abs(closestSum - target):
             closestSum = currentSum
         if currentSum == target -> return target
         else if currentSum < target -> left++
         else -> right--
4. Return closestSum.
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                // Update closest sum if closer to target
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }

                if (currentSum == target) {
                    return target;
                } else if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closestSum;
    }
};
