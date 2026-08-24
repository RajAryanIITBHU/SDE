// Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

// ==========================================
// 1. BETTER APPROACH (Hash Set)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Put all elements into unordered_set st.
2. For i from 1 to n:
     if st does not contain i -> ans.push_back(i)
3. Return ans.
*/

class SolutionBetter {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> ans;

        for (int i = 1; i <= n; i++) {
            if (st.find(i) == st.end()) {
                ans.push_back(i);
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
1. For i from 0 to n-1:
     idx = abs(nums[i]) - 1
     if nums[idx] > 0:
         nums[idx] = -nums[idx] // Mark value (idx + 1) as present
2. For i from 0 to n-1:
     if nums[i] > 0:
         ans.push_back(i + 1) // Positive value means (i + 1) never appeared
3. Return ans.
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        // Step 1: Mark visited indices as negative
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }

        // Step 2: Any index remaining positive is a disappeared number
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};
