// Link: https://leetcode.com/problems/next-greater-element-ii/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Circular Monotonic Stack - 2N Passes)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize ans array of size n with -1.
2. Initialize stack<int> st storing indices.
3. Loop from 2n - 1 down to 0:
     idx = i % n
     While !st.empty() && nums[st.top()] <= nums[idx]:
         st.pop()
     if i < n && !st.empty():
         ans[idx] = nums[st.top()]
     st.push(idx)
4. Return ans.
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st; // Stores indices

        // Traverse circularly 2 times
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;

            while (!st.empty() && nums[st.top()] <= nums[idx]) {
                st.pop();
            }

            if (i < n && !st.empty()) {
                ans[idx] = nums[st.top()];
            }

            st.push(idx);
        }

        return ans;
    }
};
