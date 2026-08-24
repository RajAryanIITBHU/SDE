// Link: https://leetcode.com/problems/binary-subarrays-with-sum/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. BETTER APPROACH (Prefix Sum + Hash Map)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Create hash map mp: prefixSum -> frequency.
2. mp[0] = 1, sum = 0, ans = 0.
3. For each x in nums:
     sum += x
     rem = sum - goal
     if mp contains rem -> ans += mp[rem]
     mp[sum]++
4. Return ans.
*/

class SolutionBetter {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum - goal;

            if (mp.find(rem) != mp.end()) {
                ans += mp[rem];
            }

            mp[sum]++;
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Sliding Window: atMost(goal) - atMost(goal - 1))
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper function atMost(k):
     if k < 0 return 0
     left = 0, sum = 0, count = 0
     For right from 0 to n-1:
         sum += nums[right]
         While sum > k:
             sum -= nums[left]
             left++
         count += (right - left + 1)
     return count
2. Return atMost(goal) - atMost(goal - 1).
*/

class Solution {
private:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int n = nums.size();
        int left = 0;
        int sum = 0;
        int count = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum > goal) {
                sum -= nums[left];
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};
