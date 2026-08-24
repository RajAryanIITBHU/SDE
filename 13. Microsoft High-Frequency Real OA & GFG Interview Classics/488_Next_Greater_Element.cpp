// Link: https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Monotonic Decreasing Stack Right-to-Left)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize ans array of size n with -1.
2. Stack st storing values.
3. For i from n-1 down to 0:
     While !st.empty() && st.top() <= arr[i]:
         st.pop()
     if !st.empty():
         ans[i] = st.top()
     st.push(arr[i])
4. Return ans.
*/

class Solution {
public:
    vector<long long> nextLargerElement(vector<long long>& arr, int n) {
        vector<long long> ans(n, -1);
        stack<long long> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top();
            }

            st.push(arr[i]);
        }

        return ans;
    }
};
