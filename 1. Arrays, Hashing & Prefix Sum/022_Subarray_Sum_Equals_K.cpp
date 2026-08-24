// Link: https://leetcode.com/problems/subarray-sum-equals-k/

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
1. Initialize ans = 0.
2. For i from 0 to n-1:
     sum = 0
     For j from i to n-1:
         sum += nums[j]
         if sum == k -> ans++
3. Return ans.
*/

class SolutionBruteForce {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Prefix Sum + Hash Map)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Create hash map mp: prefixSum -> frequency.
2. Initialize mp[0] = 1 (to handle subarrays starting at index 0).
3. Initialize sum = 0, ans = 0.
4. For each element x in nums:
     sum += x
     rem = sum - k
     if rem exists in mp:
         ans += mp[rem]
     mp[sum]++
5. Return ans.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp; // {prefixSum, count}

        mp[0] = 1; // Base case: empty prefix has sum 0
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum - k;

            // Check if there is a prefix sum such that (sum - prefixSum = k)
            if (mp.find(rem) != mp.end()) {
                ans += mp[rem];
            }

            mp[sum]++;
        }

        return ans;
    }
};
