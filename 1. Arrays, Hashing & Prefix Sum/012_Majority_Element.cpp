// Link: https://leetcode.com/problems/majority-element/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Count Frequency)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. For i from 0 to n-1:
     count = 0
     For j from 0 to n-1:
         if nums[j] == nums[i] -> count++
     if count > n/2 -> return nums[i]
2. Return -1.
*/

class SolutionBruteForce {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }
            if (count > n / 2) {
                return nums[i];
            }
        }

        return -1;
    }
};

// ==========================================
// 2. BETTER APPROACH (Hash Map Frequency Count)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Create hash map mp to store frequency of each element.
2. For each element x in nums:
     mp[x]++
     if mp[x] > n/2 -> return x
3. Return -1.
*/

class SolutionBetter {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] > n / 2) {
                return nums[i];
            }
        }

        return -1;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Boyer-Moore Voting Algorithm)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize candidate = nums[0], count = 0.
2. For each element x in nums:
     if count == 0:
         candidate = x
         count = 1
     else if x == candidate:
         count++
     else:
         count--
3. Return candidate (guaranteed majority element exists).
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = nums[0];
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};
