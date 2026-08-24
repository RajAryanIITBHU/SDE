// Link: https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (3 Loops)
// ==========================================
// Time Complexity  : O(n^3)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize maxSum = INT_MIN.
2. Loop i from 0 to n-1 (start of subarray).
3. Loop j from i to n-1 (end of subarray).
4. Calculate sum of subarray from index i to j using loop k from i to j.
5. Update maxSum = max(maxSum, sum).
6. Return maxSum.
*/

class SolutionBruteForce {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                }
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};

// ==========================================
// 2. BETTER APPROACH (2 Loops - Running Sum)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize maxSum = INT_MIN.
2. Loop i from 0 to n-1.
3. Initialize sum = 0 for the subarray starting at index i.
4. Loop j from i to n-1:
     sum += nums[j]
     maxSum = max(maxSum, sum)
5. Return maxSum.
*/

class SolutionBetter {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Kadane's Algorithm)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize maxSum = INT_MIN and sum = 0.
2. Iterate i from 0 to n-1:
     sum += nums[i]
     maxSum = max(maxSum, sum)
     // If running sum becomes negative, reset it to 0
     if sum < 0 -> sum = 0
3. Return maxSum.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxSum = max(maxSum, sum);

            // If sum becomes negative, start fresh from next element
            if (sum < 0) {
                sum = 0;
            }
        }

        return maxSum;
    }
};
