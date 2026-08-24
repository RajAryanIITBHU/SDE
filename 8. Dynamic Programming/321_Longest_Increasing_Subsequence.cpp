// Link: https://leetcode.com/problems/longest-increasing-subsequence/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Patience Sorting / Binary Search Tails)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain tails vector storing smallest tail of all increasing subsequences of various lengths.
2. For each num in nums:
     Find lower_bound index of num in tails.
     if index == tails.size() -> tails.push_back(num)
     else -> tails[index] = num
3. Return tails.size().
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);

            if (it == tails.end()) {
                tails.push_back(num); // Extends the longest subsequence found so far
            } else {
                *it = num; // Maintain the smallest possible tail for this subsequence length
            }
        }

        return tails.size();
    }
};
