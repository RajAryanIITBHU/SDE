// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Space-Optimized 2-Transaction DP)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. buy1 = INT_MIN, sell1 = 0.
2. buy2 = INT_MIN, sell2 = 0.
3. For each price in prices:
     buy1 = max(buy1, -price)
     sell1 = max(sell1, buy1 + price)
     buy2 = max(buy2, sell1 - price)
     sell2 = max(sell2, buy2 + price)
4. Return sell2.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, sell1 = 0;
        int buy2 = INT_MIN, sell2 = 0;

        for (int price : prices) {
            buy1 = max(buy1, -price);
            sell1 = max(sell1, buy1 + price);
            buy2 = max(buy2, sell1 - price);
            sell2 = max(sell2, buy2 + price);
        }

        return sell2;
    }
};
