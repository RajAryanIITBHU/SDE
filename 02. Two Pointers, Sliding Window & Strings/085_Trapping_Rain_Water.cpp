// Link: https://leetcode.com/problems/trapping-rain-water/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BETTER APPROACH (Prefix & Suffix Max Arrays)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Build leftMax array: leftMax[i] = max(height[0..i]).
2. Build rightMax array: rightMax[i] = max(height[i..n-1]).
3. ans = 0.
4. For i from 0 to n-1:
     water = min(leftMax[i], rightMax[i]) - height[i]
     ans += max(0, water)
5. Return ans.
*/

class SolutionBetter {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Two Pointers - O(1) Space)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize left = 0, right = n - 1, leftMax = 0, rightMax = 0, ans = 0.
2. While left <= right:
     if height[left] <= height[right]:
         if height[left] >= leftMax -> leftMax = height[left]
         else -> ans += leftMax - height[left]
         left++
     else:
         if height[right] >= rightMax -> rightMax = height[right]
         else -> ans += rightMax - height[right]
         right--
3. Return ans.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;

        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    ans += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    ans += rightMax - height[right];
                }
                right--;
            }
        }

        return ans;
    }
};
