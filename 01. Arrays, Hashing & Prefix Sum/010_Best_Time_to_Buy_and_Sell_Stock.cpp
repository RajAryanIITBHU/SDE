// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (All Pairs)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize maxProfit = 0.
2. For i from 0 to n-1 (buy day):
     For j from i+1 to n-1 (sell day):
         profit = prices[j] - prices[i]
         maxProfit = max(maxProfit, profit)
3. Return maxProfit.
*/

class SolutionBruteForce {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int profit = prices[j] - prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};

// ==========================================
// 2. BETTER APPROACH (Suffix Maximum Array)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n) auxiliary space
/*
PSEUDOCODE:
1. Build suffixMax array where suffixMax[i] is the highest price from day i to n-1.
2. For each day i:
     profit = suffixMax[i] - prices[i]
     maxProfit = max(maxProfit, profit)
3. Return maxProfit.
*/

class SolutionBetter {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        vector<int> suffixMax(n);
        suffixMax[n - 1] = prices[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], prices[i]);
        }

        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            int profit = suffixMax[i] - prices[i];
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Single Pass / Kadane's Style)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize minPrice = INT_MAX and maxProfit = 0.
2. Iterate i from 0 to n-1:
     minPrice = min(minPrice, prices[i])
     profit = prices[i] - minPrice
     maxProfit = max(maxProfit, profit)
3. Return maxProfit.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < n; i++) {
            // Track minimum buying price seen so far
            minPrice = min(minPrice, prices[i]);

            // Profit if sold today
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};
