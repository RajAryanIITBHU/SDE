// Link: https://leetcode.com/problems/array-nesting/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BETTER APPROACH (Visited Array)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize vis array of size n with 0, ans = 0.
2. For i from 0 to n-1:
     if !vis[i]:
         start = i
         count = 0
         while !vis[start]:
             vis[start] = 1
             start = nums[start]
             count++
         ans = max(ans, count)
3. Return ans.
*/

class SolutionBetter {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int curr = i;
                int count = 0;

                while (!vis[curr]) {
                    vis[curr] = 1;
                    curr = nums[curr];
                    count++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (In-place Visited Marking)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize ans = 0.
2. For i from 0 to n-1:
     if nums[i] != -1:
         curr = i
         count = 0
         while nums[curr] != -1:
             nextIdx = nums[curr]
             nums[curr] = -1 // Mark visited in-place
             curr = nextIdx
             count++
         ans = max(ans, count)
3. Return ans.
*/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != -1) {
                int curr = i;
                int count = 0;

                while (nums[curr] != -1) {
                    int nextIdx = nums[curr];
                    nums[curr] = -1; // In-place visited mark
                    curr = nextIdx;
                    count++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};
