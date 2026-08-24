// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (State Machine DP: Held and Free)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. held = -prices[0] - fee, free = 0.
2. For i from 1 to n-1:
     free = max(free, held + prices[i])
     held = max(held, free - prices[i] - fee)
3. Return free.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;

        int held = -prices[0] - fee; // State: holding stock (pay fee at purchase)
        int free = 0;               // State: not holding stock

        for (int i = 1; i < n; i++) {
            free = max(free, held + prices[i]);
            held = max(held, free - prices[i] - fee);
        }

        return free;
    }
};
