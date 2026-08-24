// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Single Pass Min Price Tracking)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. minPrice = INT_MAX, maxProfit = 0.
2. For each price in prices:
     minPrice = min(minPrice, price)
     maxProfit = max(maxProfit, price - minPrice)
3. Return maxProfit.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};
