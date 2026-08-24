// Link: https://leetcode.com/problems/online-stock-span/

#include <iostream>
#include <stack>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Monotonic Decreasing Stack of Pairs)
// ==========================================
// Time Complexity  : Amortized O(1) per next() call
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain stack<pair<int, int>> st storing {price, span}.
2. next(price):
     span = 1
     While !st.empty() && st.top().first <= price:
         span += st.top().second
         st.pop()
     st.push({price, span})
     return span
*/

class StockSpanner {
private:
    stack<pair<int, int>> st; // {price, span}

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;

        // Merge spans of all consecutive preceding days with price <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};
