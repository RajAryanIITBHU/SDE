// Link: https://leetcode.com/problems/continuous-subarray-sum/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (2 Nested Loops)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. For i from 0 to n-1:
     sum = nums[i]
     For j from i+1 to n-1:
         sum += nums[j]
         if sum % k == 0 -> return true
2. Return false.
*/

class SolutionBruteForce {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int sum = nums[i];
            for (int j = i + 1; j < n; j++) {
                sum += nums[j];
                if (sum % k == 0) {
                    return true;
                }
            }
        }

        return false;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Prefix Sum Remainder + Hash Map)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(min(n, k))
/*
PSEUDOCODE:
1. Create hash map mp: remainder -> earliest_index.
2. Initialize mp[0] = -1 (to handle subarrays starting at index 0).
3. sum = 0.
4. For i from 0 to n-1:
     sum += nums[i]
     rem = sum % k
     if mp.count(rem):
         if i - mp[rem] >= 2 -> return true (length at least 2)
     else:
         mp[rem] = i // Store only earliest occurrence to maximize length
5. Return false.
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp; // {remainder, first_index}

        mp[0] = -1; // Base case for subarray starting at index 0
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;

            if (mp.find(rem) != mp.end()) {
                // Check if subarray length is at least 2
                if (i - mp[rem] >= 2) {
                    return true;
                }
            } else {
                // Record first occurrence of this remainder
                mp[rem] = i;
            }
        }

        return false;
    }
};
