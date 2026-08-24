// Link: https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Kadane's Algorithm)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. maxSum = INT_MIN, sum = 0.
2. For each num in arr:
     sum += num
     maxSum = max(maxSum, sum)
     if sum < 0:
         sum = 0
3. Return maxSum.
*/

class Solution {
public:
    long long maxSubarraySum(vector<int>& arr) {
        long long maxSum = LLONG_MIN;
        long long sum = 0;

        for (int num : arr) {
            sum += num;
            maxSum = max(maxSum, sum);

            if (sum < 0) {
                sum = 0;
            }
        }

        return maxSum;
    }
};
