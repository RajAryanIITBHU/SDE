// Link: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Monotonic Decreasing Stack)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain stack initialized with INT_MAX.
2. totalCost = 0.
3. For each val in arr:
     While stack.top() <= val:
         mid = stack.top(), stack.pop()
         totalCost += mid * min(stack.top(), val)
     stack.push(val)
4. While stack.size() > 2:
     mid = stack.top(), stack.pop()
     totalCost += mid * stack.top()
5. Return totalCost.
*/

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int totalCost = 0;
        stack<int> st;
        st.push(INT_MAX);

        for (int val : arr) {
            while (st.top() <= val) {
                int mid = st.top();
                st.pop();
                totalCost += mid * min(st.top(), val);
            }
            st.push(val);
        }

        while (st.size() > 2) {
            int mid = st.top();
            st.pop();
            totalCost += mid * st.top();
        }

        return totalCost;
    }
};
