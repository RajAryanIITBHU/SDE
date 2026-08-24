// Link: https://leetcode.com/problems/candy/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (2-Pass Greedy)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize candies array of size n with 1.
2. Pass 1 (Left to Right):
     if ratings[i] > ratings[i - 1]:
         candies[i] = candies[i - 1] + 1
3. Pass 2 (Right to Left):
     if ratings[i] > ratings[i + 1]:
         candies[i] = max(candies[i], candies[i + 1] + 1)
4. Return sum(candies).
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Pass 1: Left to Right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Pass 2: Right to Left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int total = 0;
        for (int c : candies) total += c;

        return total;
    }
};
