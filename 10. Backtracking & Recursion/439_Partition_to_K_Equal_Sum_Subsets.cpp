// Link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking into K Buckets with Descending Pruning)
// ==========================================
// Time Complexity  : O(k * 2^n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. totalSum = sum(nums).
2. If totalSum % k != 0 || nums.size() < k return false.
3. target = totalSum / k.
4. Sort nums descending.
5. If nums[0] > target return false.
6. buckets array of size k initialized to 0.
7. Helper backtrack(idx, nums, buckets, target):
     if idx == nums.size() return true
     For i from 0 to k-1:
         if buckets[i] + nums[idx] > target continue
         if i > 0 && buckets[i] == buckets[i - 1] continue // Deduplicate bucket states
         buckets[i] += nums[idx]
         if backtrack(idx + 1, nums, buckets, target) return true
         buckets[i] -= nums[idx]
     return false
8. Return backtrack(0, nums, buckets, target).
*/

class Solution {
private:
    bool backtrack(int idx, vector<int>& nums, vector<int>& buckets, int target) {
        if (idx == (int)nums.size()) {
            return true;
        }

        for (int i = 0; i < (int)buckets.size(); i++) {
            if (buckets[i] + nums[idx] > target) continue;

            // Pruning: skip redundant symmetric bucket attempts
            if (i > 0 && buckets[i] == buckets[i - 1]) continue;

            buckets[i] += nums[idx];
            if (backtrack(idx + 1, nums, buckets, target)) {
                return true;
            }
            buckets[i] -= nums[idx]; // Backtrack
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1) return true;
        if ((int)nums.size() < k) return false;

        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if (totalSum % k != 0) return false;
        int target = totalSum / k;

        // Sort descending to place large elements first
        sort(nums.rbegin(), nums.rend());
        if (nums[0] > target) return false;

        vector<int> buckets(k, 0);
        return backtrack(0, nums, buckets, target);
    }
};
