// Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/

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
1. ans = 0.
2. For i from 0 to n-1:
     sum = 0
     For j from i to n-1:
         sum += nums[j]
         if sum % k == 0 -> ans++
3. Return ans.
*/

class SolutionBruteForce {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum % k == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Prefix Sum Remainder Normalization + Hash Map/Array)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(k)
/*
PSEUDOCODE:
1. Create frequency array remCount of size k initialized to 0.
2. remCount[0] = 1 (to count subarrays starting from index 0).
3. sum = 0, ans = 0.
4. For each x in nums:
     sum += x
     rem = (sum % k + k) % k (normalize negative remainders)
     ans += remCount[rem]
     remCount[rem]++
5. Return ans.
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> remCount(k, 0);

        remCount[0] = 1; // Base case
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            // Normalize remainder to stay within [0, k-1] even for negative sums
            int rem = (sum % k + k) % k;

            ans += remCount[rem];
            remCount[rem]++;
        }

        return ans;
    }
};
