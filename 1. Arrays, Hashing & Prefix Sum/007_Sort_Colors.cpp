// Link: https://leetcode.com/problems/sort-colors/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Standard Sorting)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Use standard C++ sort: sort(nums.begin(), nums.end()).
*/

class SolutionBruteForce {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

// ==========================================
// 2. BETTER APPROACH (Counting / 2 Passes)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Count frequencies of 0, 1, and 2 (c0, c1, c2).
2. Overwrite nums with c0 zeros, c1 ones, and c2 twos.
*/

class SolutionBetter {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int c0 = 0, c1 = 0, c2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) c0++;
            else if (nums[i] == 1) c1++;
            else c2++;
        }

        int i = 0;
        while (c0--) nums[i++] = 0;
        while (c1--) nums[i++] = 1;
        while (c2--) nums[i++] = 2;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Dutch National Flag - 1 Pass)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize low = 0, mid = 0, high = n - 1.
2. While mid <= high:
     a. If nums[mid] == 0:
          swap(nums[low], nums[mid])
          low++, mid++
     b. If nums[mid] == 1:
          mid++
     c. If nums[mid] == 2:
          swap(nums[mid], nums[high])
          high--
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
