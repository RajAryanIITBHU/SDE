// Link: https://leetcode.com/problems/contiguous-array/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

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
     zeros = 0, ones = 0
     For j from i to n-1:
         if nums[j] == 0 -> zeros++
         else -> ones++
         if zeros == ones -> ans = max(ans, j - i + 1)
3. Return ans.
*/

class SolutionBruteForce {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int zeros = 0;
            int ones = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 0) zeros++;
                else ones++;

                if (zeros == ones) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Prefix Sum: 0 as -1 + Hash Map)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Treat 0 as -1 and 1 as +1.
2. Problem reduces to finding the longest subarray with sum = 0.
3. Create hash map mp: prefixSum -> earliest_index.
4. mp[0] = -1.
5. sum = 0, ans = 0.
6. For i from 0 to n-1:
     sum += (nums[i] == 1 ? 1 : -1)
     if mp contains sum:
         ans = max(ans, i - mp[sum])
     else:
         mp[sum] = i
7. Return ans.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp; // {prefixSum, first_index}

        mp[0] = -1; // Base case for subarray starting at index 0
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // Treat 0 as -1
            sum += (nums[i] == 1) ? 1 : -1;

            if (mp.find(sum) != mp.end()) {
                ans = max(ans, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }

        return ans;
    }
};
