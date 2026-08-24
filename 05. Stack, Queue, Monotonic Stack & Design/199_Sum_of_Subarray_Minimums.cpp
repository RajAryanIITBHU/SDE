// Link: https://leetcode.com/problems/sum-of-subarray-minimums/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Monotonic Stack - Contribution of Each Element)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. For each index i, find:
     prevLess[i]: number of elements to left where arr[j] > arr[i] (+ 1)
     nextLess[i]: number of elements to right where arr[j] >= arr[i] (+ 1)
2. Total subarrays where arr[i] is minimum = prevLess[i] * nextLess[i].
3. Contribution = (arr[i] * prevLess[i] * nextLess[i]) % MOD.
4. Sum contributions for all i and return ans.
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> prevLess(n), nextLess(n);
        stack<int> st;

        // Previous strictly less element distance
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            prevLess[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next less or equal element distance
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nextLess[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long count = (1LL * prevLess[i] * nextLess[i]) % MOD;
            long long totalVal = (count * arr[i]) % MOD;
            ans = (ans + totalVal) % MOD;
        }

        return ans;
    }
};
