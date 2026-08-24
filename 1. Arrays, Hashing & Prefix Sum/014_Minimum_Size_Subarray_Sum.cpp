// Link: https://leetcode.com/problems/minimum-size-subarray-sum/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (2 Nested Loops)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize ans = INT_MAX.
2. For i from 0 to n-1:
     sum = 0
     For j from i to n-1:
         sum += nums[j]
         if sum >= target:
             ans = min(ans, j - i + 1)
             break
3. Return ans == INT_MAX ? 0 : ans.
*/

class SolutionBruteForce {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum >= target) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};

// ==========================================
// 2. BETTER APPROACH (Prefix Sum + Binary Search)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Build prefix sum array PS of size n+1 (1-indexed).
2. For each i from 0 to n:
     Search for smallest j such that PS[j] >= PS[i] + target using lower_bound.
     If found, update ans = min(ans, j - i).
3. Return ans == INT_MAX ? 0 : ans.
*/

class SolutionBetter {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> PS(n + 1, 0);

        for (int i = 0; i < n; i++) {
            PS[i + 1] = PS[i] + nums[i];
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int needed = PS[i] + target;
            auto it = lower_bound(PS.begin(), PS.end(), needed);

            if (it != PS.end()) {
                int j = it - PS.begin();
                ans = min(ans, j - i);
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Sliding Window / Two Pointers)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize left = 0, sum = 0, ans = INT_MAX.
2. For right from 0 to n-1:
     sum += nums[right]
     While sum >= target:
         ans = min(ans, right - left + 1)
         sum -= nums[left]
         left++
3. Return ans == INT_MAX ? 0 : ans.
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            // Shrink window from the left as long as condition is satisfied
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};
