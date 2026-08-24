// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Space-Optimized K-Transaction DP)
// ==========================================
// Time Complexity  : O(k * n)
// Space Complexity : O(k)
/*
PSEUDOCODE:
1. If k >= n / 2: return simple unlimited profit sum where prices[i] > prices[i-1].
2. buy array of size k + 1 with INT_MIN, sell array of size k + 1 with 0.
3. For each price in prices:
     For j from 1 to k:
         buy[j] = max(buy[j], sell[j - 1] - price)
         sell[j] = max(sell[j], buy[j] + price)
4. Return sell[k].
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        // If k >= n/2, can make as many transactions as possible
        if (k >= n / 2) {
            int maxProf = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    maxProf += prices[i] - prices[i - 1];
                }
            }
            return maxProf;
        }

        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);

        for (int price : prices) {
            for (int j = 1; j <= k; j++) {
                buy[j] = max(buy[j], sell[j - 1] - price);
                sell[j] = max(sell[j], buy[j] + price);
            }
        }

        return sell[k];
    }
};
