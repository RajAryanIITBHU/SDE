// Link: https://leetcode.com/problems/missing-number/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Linear Search for 0..n)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. For num from 0 to n:
     found = false
     For each x in nums:
         if x == num:
             found = true
             break
     if !found -> return num
2. Return -1.
*/

class SolutionBruteForce {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        for (int num = 0; num <= n; num++) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (nums[i] == num) {
                    found = true;
                    break;
                }
            }
            if (!found) return num;
        }

        return -1;
    }
};

// ==========================================
// 2. BETTER APPROACH (Sorting)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Sort nums.
2. For i from 0 to n-1:
     if nums[i] != i -> return i
3. Return n.
*/

class SolutionBetter {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                return i;
            }
        }

        return n;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH 1 (Math Formula: Sum)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. expectedSum = n * (n + 1) / 2.
2. actualSum = sum of all elements in nums.
3. Return expectedSum - actualSum.
*/

class SolutionMath {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;

        for (int i = 0; i < n; i++) {
            actualSum += nums[i];
        }

        return expectedSum - actualSum;
    }
};

// ==========================================
// 4. OPTIMAL APPROACH 2 (Bit Manipulation: XOR)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize ans = n.
2. For i from 0 to n-1:
     ans = ans ^ i ^ nums[i]
3. Return ans.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;

        for (int i = 0; i < n; i++) {
            ans ^= i ^ nums[i];
        }

        return ans;
    }
};
