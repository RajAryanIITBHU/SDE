// Link: https://www.geeksforgeeks.org/problems/rod-cutting0840/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Unbounded Knapsack 1D Dynamic Programming)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. dp array of size n + 1 initialized to 0.
2. For i from 0 to n-1:
     rodLen = i + 1
     For j from rodLen to n:
         dp[j] = max(dp[j], price[i] + dp[j - rodLen])
3. Return dp[n].
*/

class Solution {
public:
    int cutRod(vector<int>& price) {
        int n = price.size();
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int rodLen = i + 1;
            for (int j = rodLen; j <= n; j++) {
                dp[j] = max(dp[j], price[i] + dp[j - rodLen]);
            }
        }

        return dp[n];
    }
};
