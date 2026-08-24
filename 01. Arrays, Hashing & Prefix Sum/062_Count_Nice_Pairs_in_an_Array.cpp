// Link: https://leetcode.com/problems/count-nice-pairs-in-an-array/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Algebraic Rearrangement + Hash Map)
// ==========================================
// Time Complexity  : O(n * log10(max_val))
// Space Complexity : O(n)
/*
PSEUDOCODE:
Equation: nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Rearranges to: nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])

1. Helper rev(x): returns reversed number of x.
2. Create hash map mp: (x - rev(x)) -> frequency.
3. ans = 0, MOD = 1e9 + 7.
4. For each x in nums:
     diff = x - rev(x)
     ans = (ans + mp[diff]) % MOD
     mp[diff]++
5. Return ans.
*/

class Solution {
private:
    int rev(int n) {
        int reversedNum = 0;
        while (n > 0) {
            reversedNum = reversedNum * 10 + (n % 10);
            n /= 10;
        }
        return reversedNum;
    }

public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp; // {nums[i] - rev(nums[i]), count}
        long long ans = 0;
        int MOD = 1e9 + 7;

        for (int x : nums) {
            int diff = x - rev(x);

            // Add previous occurrences with same difference
            ans = (ans + mp[diff]) % MOD;
            mp[diff]++;
        }

        return ans;
    }
};
