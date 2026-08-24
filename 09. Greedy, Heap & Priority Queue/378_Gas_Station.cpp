// Link: https://leetcode.com/problems/gas-station/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Single Pass Surplus Tracking)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. totalSurplus = 0, currentSurplus = 0, startStation = 0.
2. For i from 0 to n-1:
     diff = gas[i] - cost[i]
     totalSurplus += diff
     currentSurplus += diff
     if currentSurplus < 0:
         startStation = i + 1
         currentSurplus = 0
3. Return totalSurplus >= 0 ? startStation : -1.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalSurplus = 0;
        int currentSurplus = 0;
        int startStation = 0;

        for (int i = 0; i < (int)gas.size(); i++) {
            int diff = gas[i] - cost[i];
            totalSurplus += diff;
            currentSurplus += diff;

            // If tank drops below 0, station 0..i cannot be the starting point
            if (currentSurplus < 0) {
                startStation = i + 1;
                currentSurplus = 0;
            }
        }

        return (totalSurplus >= 0) ? startStation : -1;
    }
};
