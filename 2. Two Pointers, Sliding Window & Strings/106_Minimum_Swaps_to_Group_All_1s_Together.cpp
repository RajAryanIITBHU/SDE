// Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Fixed Sliding Window of Size totalOnes)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. totalOnes = count of 1s in data.
2. If totalOnes <= 1 return 0.
3. Count 1s in the first window of size totalOnes: currentOnes.
4. maxOnesInWindow = currentOnes.
5. For i from totalOnes to n-1:
     currentOnes += data[i] - data[i - totalOnes]
     maxOnesInWindow = max(maxOnesInWindow, currentOnes)
6. Minimum swaps needed = totalOnes - maxOnesInWindow.
7. Return totalOnes - maxOnesInWindow.
*/

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        int totalOnes = 0;

        for (int x : data) {
            totalOnes += x;
        }

        if (totalOnes <= 1) return 0;

        int currentOnes = 0;
        for (int i = 0; i < totalOnes; i++) {
            currentOnes += data[i];
        }

        int maxOnesInWindow = currentOnes;

        for (int i = totalOnes; i < n; i++) {
            currentOnes += data[i] - data[i - totalOnes];
            maxOnesInWindow = max(maxOnesInWindow, currentOnes);
        }

        return totalOnes - maxOnesInWindow;
    }
};
