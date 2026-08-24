// Link: https://leetcode.com/problems/sum-of-subarray-ranges/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sum of Subarray Maxes - Sum of Subarray Mins)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
Subarray Range = max(sub) - min(sub).
Sum of all ranges = (Sum of all subarray maximums) - (Sum of all subarray minimums).
Compute both in O(n) using monotonic stack.
1. Return sumSubarrayMaxs(nums) - sumSubarrayMins(nums).
*/

class Solution {
private:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ple(n), nle(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; i++) {
            total += (long long)(i - ple[i]) * (nle[i] - i) * arr[i];
        }
        return total;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> pge(n), nge(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; i++) {
            total += (long long)(i - pge[i]) * (nge[i] - i) * arr[i];
        }
        return total;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
