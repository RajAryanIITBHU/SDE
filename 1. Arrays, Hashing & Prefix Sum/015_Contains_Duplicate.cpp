// Link: https://leetcode.com/problems/contains-duplicate/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (All Pairs)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. For i from 0 to n-1:
     For j from i+1 to n-1:
         if nums[i] == nums[j] -> return true
2. Return false.
*/

class SolutionBruteForce {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        return false;
    }
};

// ==========================================
// 2. BETTER APPROACH (Sorting)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Sort array: sort(nums.begin(), nums.end()).
2. For i from 1 to n-1:
     if nums[i] == nums[i-1] -> return true
3. Return false.
*/

class SolutionBetter {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Hash Set)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize unordered_set st.
2. For each element x in nums:
     if st contains x -> return true
     st.insert(x)
3. Return false.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for (int x : nums) {
            if (st.find(x) != st.end()) {
                return true;
            }
            st.insert(x);
        }

        return false;
    }
};
