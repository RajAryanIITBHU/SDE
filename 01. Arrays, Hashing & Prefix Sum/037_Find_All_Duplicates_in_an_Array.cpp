// Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

// ==========================================
// 1. BETTER APPROACH (Hash Set)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize unordered_set st and vector ans.
2. For each x in nums:
     if st contains x -> ans.push_back(x)
     else -> st.insert(x)
3. Return ans.
*/

class SolutionBetter {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> ans;

        for (int x : nums) {
            if (st.count(x)) {
                ans.push_back(x);
            } else {
                st.insert(x);
            }
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (In-place Sign Negation)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. Initialize ans.
2. For i from 0 to n-1:
     idx = abs(nums[i]) - 1
     // If value at index is already negative, we've seen this number before!
     if nums[idx] < 0:
         ans.push_back(abs(nums[i]))
     else:
         nums[idx] = -nums[idx] // Mark as visited by making it negative
3. Return ans.
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;

            // If already visited, it is a duplicate
            if (nums[idx] < 0) {
                ans.push_back(abs(nums[i]));
            } else {
                nums[idx] = -nums[idx]; // Mark as visited
            }
        }

        return ans;
    }
};
