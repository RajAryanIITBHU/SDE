// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (State Machine DP: Held, Sold, Rest)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. held = -prices[0], sold = 0, rest = 0.
2. For i from 1 to n-1:
     prevSold = sold
     sold = held + prices[i]
     held = max(held, rest - prices[i])
     rest = max(rest, prevSold)
3. Return max(sold, rest).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int held = -prices[0]; // State: holding a stock
        int sold = 0;          // State: just sold a stock
        int rest = 0;          // State: cooling down or resting

        for (int i = 1; i < (int)prices.size(); i++) {
            int prevSold = sold;
            sold = held + prices[i];
            held = max(held, rest - prices[i]);
            rest = max(rest, prevSold);
        }

        return max(sold, rest);
    }
};
