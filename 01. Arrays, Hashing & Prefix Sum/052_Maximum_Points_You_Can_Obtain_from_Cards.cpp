// Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BETTER APPROACH (Prefix & Suffix Window Sums)
// ==========================================
// Time Complexity  : O(k)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Calculate sum of first k elements: leftSum.
2. Initialize ans = leftSum, rightSum = 0.
3. For i from 0 to k-1:
     leftSum -= cardPoints[k - 1 - i]
     rightSum += cardPoints[n - 1 - i]
     ans = max(ans, leftSum + rightSum)
4. Return ans.
*/

class SolutionBetter {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0;

        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }

        int ans = leftSum;
        int rightSum = 0;

        for (int i = 0; i < k; i++) {
            leftSum -= cardPoints[k - 1 - i];
            rightSum += cardPoints[n - 1 - i];
            ans = max(ans, leftSum + rightSum);
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Sliding Window: Minimize Remaining Subarray)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Window size to exclude = windowSize = n - k.
2. If windowSize == 0 -> return sum of all cards.
3. Find minimum sum subarray of size windowSize.
4. Return totalSum - minSubarraySum.
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowSize = n - k;
        int totalSum = 0;

        for (int x : cardPoints) {
            totalSum += x;
        }

        if (windowSize == 0) return totalSum;

        int windowSum = 0;
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        int minWindowSum = windowSum;

        for (int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i] - cardPoints[i - windowSize];
            minWindowSum = min(minWindowSum, windowSum);
        }

        return totalSum - minWindowSum;
    }
};
