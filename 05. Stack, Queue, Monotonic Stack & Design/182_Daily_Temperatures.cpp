// Link: https://leetcode.com/problems/daily-temperatures/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Monotonic Decreasing Stack of Indices)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize ans array of size n with 0.
2. Initialize stack<int> st storing indices.
3. For i from 0 to n-1:
     While !st.empty() && temperatures[i] > temperatures[st.top()]:
         prevDay = st.top(), st.pop()
         ans[prevDay] = i - prevDay
     st.push(i)
4. Return ans.
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st; // Stores indices of days

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevDay = st.top();
                st.pop();
                ans[prevDay] = i - prevDay;
            }
            st.push(i);
        }

        return ans;
    }
};
