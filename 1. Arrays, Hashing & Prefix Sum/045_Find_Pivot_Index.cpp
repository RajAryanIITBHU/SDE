// Link: https://leetcode.com/problems/find-pivot-index/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// ==========================================
// 1. BETTER APPROACH (Prefix & Suffix Sum Arrays)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Build prefix sum array leftSum and suffix sum array rightSum.
2. For i from 0 to n-1:
     if leftSum[i] == rightSum[i] -> return i
3. Return -1.
*/

class SolutionBetter {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n, 0);
        vector<int> rightSum(n, 0);

        for (int i = 1; i < n; i++) {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            if (leftSum[i] == rightSum[i]) {
                return i;
            }
        }

        return -1;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Total Sum - Running Left Sum)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. totalSum = sum of all elements in nums.
2. leftSum = 0.
3. For i from 0 to n-1:
     rightSum = totalSum - leftSum - nums[i]
     if leftSum == rightSum:
         return i
     leftSum += nums[i]
4. Return -1.
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for (int x : nums) {
            totalSum += x;
        }

        int leftSum = 0;

        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];

            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};
