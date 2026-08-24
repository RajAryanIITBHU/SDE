// Link: https://www.geeksforgeeks.org/problems/shortest-job-first/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Burst Time Sorting)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Sort burst times bt in ascending order.
2. totalWaitTime = 0, currentWaitTime = 0.
3. For i from 0 to n-2:
     currentWaitTime += bt[i]
     totalWaitTime += currentWaitTime
4. Return totalWaitTime / n.
*/

class Solution {
public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());

        long long totalWaitTime = 0;
        long long currentWaitTime = 0;
        int n = bt.size();

        for (int i = 0; i < n - 1; i++) {
            currentWaitTime += bt[i];
            totalWaitTime += currentWaitTime;
        }

        return totalWaitTime / n;
    }
};
