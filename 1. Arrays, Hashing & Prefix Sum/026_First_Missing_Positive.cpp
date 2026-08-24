// Link: https://leetcode.com/problems/first-missing-positive/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Search 1, 2, 3...)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. For target from 1 to n+1:
     found = false
     For each x in nums:
         if x == target:
             found = true
             break
     if !found -> return target
2. Return 1.
*/

class SolutionBruteForce {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int target = 1; target <= n + 1; target++) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (nums[i] == target) {
                    found = true;
                    break;
                }
            }
            if (!found) return target;
        }

        return 1;
    }
};

// ==========================================
// 2. BETTER APPROACH (Hash Set)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Put all elements of nums into unordered_set st.
2. For target from 1 to n+1:
     if st does not contain target -> return target
3. Return 1.
*/

class SolutionBetter {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());

        for (int target = 1; target <= n + 1; target++) {
            if (st.find(target) == st.end()) {
                return target;
            }
        }

        return 1;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Cyclic Sort / In-place Index Mapping)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. For i from 0 to n-1:
     // Place number x at index (x - 1) if 1 <= x <= n
     While nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]:
         swap(nums[i], nums[nums[i] - 1])
2. Scan array from i = 0 to n-1:
     if nums[i] != i + 1:
         return i + 1
3. Return n + 1 (if all 1..n are present).
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Cyclic sort - place each number at its correct index (val at index val - 1)
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: Find the first index where value is not (index + 1)
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // Step 3: If 1 through n are all present
        return n + 1;
    }
};
