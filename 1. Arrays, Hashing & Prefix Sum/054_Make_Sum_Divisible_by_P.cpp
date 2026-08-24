// Link: https://leetcode.com/problems/make-sum-divisible-by-p/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Prefix Sum Remainder + Hash Map)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. totalSum = sum of all elements in nums modulo p.
2. If totalSum % p == 0 -> return 0 (already divisible).
3. targetRem = totalSum % p.
4. Create hash map mp: remainder -> latest_index.
5. mp[0] = -1, sum = 0, minLen = n.
6. For i from 0 to n-1:
     sum = (sum + nums[i]) % p
     neededRem = (sum - targetRem + p) % p
     if mp contains neededRem:
         minLen = min(minLen, i - mp[neededRem])
     mp[sum] = i
7. Return minLen >= n ? -1 : minLen.
*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totalSum = 0;

        for (int x : nums) {
            totalSum += x;
        }

        int targetRem = totalSum % p;
        if (targetRem == 0) return 0; // Already divisible

        unordered_map<int, int> mp; // {remainder, latest_index}
        mp[0] = -1;

        int sum = 0;
        int minLen = n;

        for (int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % p;
            int neededRem = (sum - targetRem + p) % p;

            if (mp.find(neededRem) != mp.end()) {
                minLen = min(minLen, i - mp[neededRem]);
            }

            mp[sum] = i;
        }

        return (minLen >= n) ? -1 : minLen;
    }
};
