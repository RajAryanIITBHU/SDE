// Link: https://leetcode.com/problems/sum-of-subarray-ranges/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Monotonic Stack: Sum of Maximums - Sum of Minimums)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
Sum of Ranges = (Sum of Subarray Maximums) - (Sum of Subarray Minimums)
1. For Subarray Minimums:
     Use monotonic stack to calculate left & right spans for each element as min.
2. For Subarray Maximums:
     Use monotonic stack to calculate left & right spans for each element as max.
3. Return sumMax - sumMin.
*/

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sumMin = 0, sumMax = 0;

        // --- Calculate Sum of Minimums ---
        vector<int> prevLess(n), nextLess(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            prevLess[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            nextLess[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        while (!st.empty()) st.pop();

        for (int i = 0; i < n; i++) {
            sumMin += 1LL * nums[i] * prevLess[i] * nextLess[i];
        }

        // --- Calculate Sum of Maximums ---
        vector<int> prevGreater(n), nextGreater(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            prevGreater[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            nextGreater[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            sumMax += 1LL * nums[i] * prevGreater[i] * nextGreater[i];
        }

        return sumMax - sumMin;
    }
};
