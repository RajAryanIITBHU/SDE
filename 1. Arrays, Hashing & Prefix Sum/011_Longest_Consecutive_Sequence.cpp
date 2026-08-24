// Link: https://leetcode.com/problems/longest-consecutive-sequence/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Linear Search for Sequence)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If nums is empty, return 0.
2. Initialize ans = 1.
3. For each element x in nums:
     currentNum = x
     count = 1
     While (currentNum + 1) exists in nums:
         currentNum++
         count++
     ans = max(ans, count)
4. Return ans.
*/

class SolutionBruteForce {
private:
    bool linearSearch(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) return true;
        }
        return false;
    }

public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int ans = 1;

        for (int i = 0; i < n; i++) {
            int currentNum = nums[i];
            int count = 1;

            while (linearSearch(nums, currentNum + 1)) {
                currentNum++;
                count++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};

// ==========================================
// 2. BETTER APPROACH (Sorting)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If nums is empty, return 0.
2. Sort nums: sort(nums.begin(), nums.end()).
3. Initialize ans = 1, count = 1.
4. For i from 1 to n-1:
     If nums[i] == nums[i-1] -> continue (ignore duplicates)
     If nums[i] == nums[i-1] + 1 -> count++
     Else -> count = 1
     ans = max(ans, count)
5. Return ans.
*/

class SolutionBetter {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        sort(nums.begin(), nums.end());

        int ans = 1;
        int count = 1;

        for (int i = 1; i < n; i++) {
            // Skip duplicates
            if (nums[i] == nums[i - 1]) continue;

            if (nums[i] == nums[i - 1] + 1) {
                count++;
            } else {
                count = 1;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Hash Set - Intelligent Start)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Insert all elements of nums into unordered_set 'st'.
2. Initialize ans = 0.
3. For each element x in st:
     // If (x - 1) is NOT in set, then x is the START of a consecutive sequence
     if st.find(x - 1) == st.end():
         currentNum = x
         count = 1
         while st.find(currentNum + 1) != st.end():
             currentNum++
             count++
         ans = max(ans, count)
4. Return ans.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;

        for (int x : st) {
            // Check if x is the starting element of a sequence
            if (st.find(x - 1) == st.end()) {
                int currentNum = x;
                int count = 1;

                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    count++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};
