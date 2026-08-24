// Link: https://leetcode.com/problems/sum-of-subarray-minimums/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Monotonic Stack PLE & NLE)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
For each element arr[i], count subarrays where arr[i] is the minimum:
  (i - PLE[i]) * (NLE[i] - i) * arr[i]
1. Compute Previous Less Element (PLE) indices using monotonic stack.
2. Compute Next Less or Equal Element (NLE) indices using monotonic stack.
3. totalSum = sum of ((i - ple[i]) * (nle[i] - i) * arr[i]) % MOD.
4. Return totalSum.
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> ple(n), nle(n);
        stack<int> st;

        // Find Previous Less Element (Strictly smaller)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Find Next Less or Equal Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            long long leftCount = i - ple[i];
            long long rightCount = nle[i] - i;
            long long contribution = (leftCount * rightCount) % MOD;
            contribution = (contribution * arr[i]) % MOD;
            totalSum = (totalSum + contribution) % MOD;
        }

        return totalSum;
    }
};
