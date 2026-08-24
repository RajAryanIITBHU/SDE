// Link: https://leetcode.com/problems/minimum-number-of-refueling-stops/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Max-Heap Greedy Past Gas Stations)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Max-heap pq of available fuel amounts passed.
2. currentFuel = startFuel, stops = 0, stationIdx = 0.
3. While currentFuel < target:
     While stationIdx < stations.size() && stations[stationIdx][0] <= currentFuel:
         pq.push(stations[stationIdx][1])
         stationIdx++
     if pq.empty() return -1 (cannot reach next station or target)
     currentFuel += pq.top(), pq.pop()
     stops++
4. Return stops.
*/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq; // Max-heap of fuel capacities passed
        int currentFuel = startFuel;
        int stops = 0;
        int i = 0;
        int n = stations.size();

        while (currentFuel < target) {
            // Push all gas stations reachable with current fuel
            while (i < n && stations[i][0] <= currentFuel) {
                pq.push(stations[i][1]);
                i++;
            }

            if (pq.empty()) {
                return -1; // Cannot advance further
            }

            currentFuel += pq.top(); // Refuel with maximum available fuel
            pq.pop();
            stops++;
        }

        return stops;
    }
};
