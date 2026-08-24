// Link: https://leetcode.com/problems/grumpy-bookstore-owner/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Fixed Sliding Window)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Calculate alreadySatisfied: sum of customers[i] where grumpy[i] == 0.
2. Find maxExtra customers satisfied by turning grumpy off in a window of size minutes:
     extra = sum of customers[i] where grumpy[i] == 1 for first minutes.
     maxExtra = extra.
     For i from minutes to n-1:
         if grumpy[i] == 1 -> extra += customers[i]
         if grumpy[i - minutes] == 1 -> extra -= customers[i - minutes]
         maxExtra = max(maxExtra, extra)
3. Return alreadySatisfied + maxExtra.
*/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int alreadySatisfied = 0;

        // Base satisfied customers without applying secret technique
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                alreadySatisfied += customers[i];
            }
        }

        // Window to maximize extra satisfied grumpy customers
        int extra = 0;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                extra += customers[i];
            }
        }

        int maxExtra = extra;

        for (int i = minutes; i < n; i++) {
            if (grumpy[i] == 1) extra += customers[i];
            if (grumpy[i - minutes] == 1) extra -= customers[i - minutes];

            maxExtra = max(maxExtra, extra);
        }

        return alreadySatisfied + maxExtra;
    }
};
