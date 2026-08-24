// Link: https://leetcode.com/problems/subarrays-with-k-different-integers/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sliding Window: atMost(k) - atMost(k - 1))
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Helper atMost(k):
     Create hash map mp: element -> frequency.
     left = 0, count = 0.
     For right from 0 to n-1:
         mp[nums[right]]++
         While mp.size() > k:
             mp[nums[left]]--
             if mp[nums[left]] == 0 -> mp.erase(nums[left])
             left++
         count += (right - left + 1)
     return count
2. Return atMost(k) - atMost(k - 1).
*/

class Solution {
private:
    int atMost(vector<int>& nums, int k) {
        if (k == 0) return 0;

        int n = nums.size();
        unordered_map<int, int> mp;
        int left = 0;
        int count = 0;

        for (int right = 0; right < n; right++) {
            mp[nums[right]]++;

            while ((int)mp.size() > k) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
