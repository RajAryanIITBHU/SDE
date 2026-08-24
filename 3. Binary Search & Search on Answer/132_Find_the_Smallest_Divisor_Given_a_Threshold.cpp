// Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Divisor)
// ==========================================
// Time Complexity  : O(n * log(max(nums)))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper computeSum(divisor):
     sum = 0
     For each x in nums:
         sum += (x + divisor - 1) / divisor // ceil(x / divisor)
     return sum
2. Search range: low = 1, high = max(nums), ans = high.
3. While low <= high:
     mid = low + (high - low) / 2
     if computeSum(mid) <= threshold:
         ans = mid
         high = mid - 1 // Try smaller divisor
     else:
         low = mid + 1
4. Return ans.
*/

class Solution {
private:
    long long computeSum(vector<int>& nums, int divisor) {
        long long sum = 0;
        for (int x : nums) {
            sum += (x + divisor - 1) / divisor;
        }
        return sum;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (computeSum(nums, mid) <= threshold) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
