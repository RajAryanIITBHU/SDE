// Link: https://leetcode.com/problems/get-equal-substrings-within-budget/

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sliding Window: Cost <= maxCost)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize left = 0, currentCost = 0, ans = 0.
2. For right from 0 to n-1:
     currentCost += abs(s[right] - t[right])
     While currentCost > maxCost:
         currentCost -= abs(s[left] - t[left])
         left++
     ans = max(ans, right - left + 1)
3. Return ans.
*/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int left = 0;
        int currentCost = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            currentCost += abs(s[right] - t[right]);

            // Shrink window if cost exceeds budget
            while (currentCost > maxCost) {
                currentCost -= abs(s[left] - t[left]);
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
