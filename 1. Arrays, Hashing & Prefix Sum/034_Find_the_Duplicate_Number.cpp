// Link: https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Sorting)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(1) or O(n) (modifies input if in-place)
/*
PSEUDOCODE:
1. Sort nums: sort(nums.begin(), nums.end()).
2. For i from 1 to n-1:
     if nums[i] == nums[i-1] -> return nums[i]
3. Return -1.
*/

class SolutionBruteForce {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                return arr[i];
            }
        }

        return -1;
    }
};

// ==========================================
// 2. BETTER APPROACH (Hash Set)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize unordered_set st.
2. For each x in nums:
     if st contains x -> return x
     st.insert(x)
3. Return -1.
*/

class SolutionBetter {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for (int x : nums) {
            if (st.count(x)) {
                return x;
            }
            st.insert(x);
        }

        return -1;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Floyd's Tortoise and Hare / Cycle Detection)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) in-place without modifying array
/*
PSEUDOCODE:
1. Initialize slow = nums[0], fast = nums[0].
2. Move slow 1 step (nums[slow]) and fast 2 steps (nums[nums[fast]]) until slow == fast.
3. Reset fast = nums[0].
4. Move both slow and fast 1 step at a time until slow == fast.
5. Return slow (the cycle entry point / duplicate number).
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Step 1: Detect cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Step 2: Find cycle entrance (duplicate value)
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
