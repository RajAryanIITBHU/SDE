// Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BETTER APPROACH (Sorting + Two Pointers)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Sort nums.
2. Initialize i = 0, j = 1, ans = 0.
3. While i < n and j < n:
     if i == j -> j++
     diff = nums[j] - nums[i]
     if diff == k:
         ans++
         i++, j++
         Skip duplicates for i and j.
     else if diff < k:
         j++
     else:
         i++
4. Return ans.
*/

class SolutionBetter {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        int i = 0;
        int j = 1;

        while (i < n && j < n) {
            if (i == j || nums[j] - nums[i] < k) {
                j++;
            } else if (nums[j] - nums[i] > k) {
                i++;
            } else { // difference == k
                ans++;
                i++;
                j++;

                // Skip duplicate elements
                while (i < n && nums[i] == nums[i - 1]) i++;
                while (j < n && nums[j] == nums[j - 1]) j++;
            }
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Frequency Hash Map)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. If k < 0 return 0.
2. Build frequency map mp for all elements in nums.
3. For each pair {num, count} in mp:
     if k == 0:
         if count >= 2 -> ans++ (pair with same number)
     else:
         if mp contains (num + k) -> ans++
4. Return ans.
*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;

        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }

        int ans = 0;

        for (auto& it : mp) {
            int num = it.first;
            int count = it.second;

            // Case 1: k == 0, need at least 2 occurrences of same element
            if (k == 0) {
                if (count >= 2) ans++;
            } 
            // Case 2: k > 0, check if (num + k) exists
            else {
                if (mp.find(num + k) != mp.end()) ans++;
            }
        }

        return ans;
    }
};
