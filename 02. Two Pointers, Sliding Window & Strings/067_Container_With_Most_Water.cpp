// Link: https://leetcode.com/problems/container-with-most-water/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (All Pairs)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize ans = 0.
2. For i from 0 to n-1:
     For j from i+1 to n-1:
         h = min(height[i], height[j])
         w = j - i
         ans = max(ans, h * w)
3. Return ans.
*/

class SolutionBruteForce {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int h = min(height[i], height[j]);
                int w = j - i;
                ans = max(ans, h * w);
            }
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Two Pointers - Shrinking)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize left = 0, right = n - 1, ans = 0.
2. While left < right:
     h = min(height[left], height[right])
     w = right - left
     ans = max(ans, h * w)
     // Move the pointer pointing to the shorter line inward
     if height[left] < height[right]:
         left++
     else:
         right--
3. Return ans.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int ans = 0;

        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            ans = max(ans, h * w);

            // Shorter boundary limits the area, advance it
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};
