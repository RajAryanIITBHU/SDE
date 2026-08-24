// Link: https://leetcode.com/problems/count-number-of-nice-subarrays/

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
1. Treat odd numbers as 1 and even numbers as 0.
2. Problem reduces to Subarray Sum Equals K.
3. Use hash map mp: prefixSum -> frequency.
4. mp[0] = 1, sum = 0, ans = 0.
5. For each x in nums:
     sum += (x % 2 != 0 ? 1 : 0)
     rem = sum - k
     if mp contains rem -> ans += mp[rem]
     mp[sum]++
6. Return ans.
*/

class SolutionBetter {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            sum += (nums[i] % 2 != 0) ? 1 : 0;
            int rem = sum - k;

            if (mp.find(rem) != mp.end()) {
                ans += mp[rem];
            }

            mp[sum]++;
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Sliding Window: atMost(k) - atMost(k - 1))
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper function atMost(k):
     if k < 0 return 0
     left = 0, oddCount = 0, count = 0
     For right from 0 to n-1:
         if nums[right] % 2 != 0 -> oddCount++
         While oddCount > k:
             if nums[left] % 2 != 0 -> oddCount--
             left++
         count += (right - left + 1)
     return count
2. Return atMost(k) - atMost(k - 1).
*/

class Solution {
private:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int n = nums.size();
        int left = 0;
        int oddCount = 0;
        int count = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] % 2 != 0) {
                oddCount++;
            }

            while (oddCount > k) {
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
