// Link: https://leetcode.com/problems/car-fleet/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sort by Position Descending + Time Comparison)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Combine position and speed into pairs and sort descending by position.
2. fleets = 0, lastTime = 0.0.
3. For each car (pos, speed):
     timeToTarget = (double)(target - pos) / speed
     if timeToTarget > lastTime:
         fleets++
         lastTime = timeToTarget // This car is slower and forms a new fleet lead
4. Return fleets.
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n);

        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }

        // Sort cars descending by starting position (closest to target first)
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double lastTime = 0.0;

        for (auto& car : cars) {
            double timeToTarget = (double)(target - car.first) / car.second;

            // If this car takes more time than current fleet leader, it becomes leader of a new fleet
            if (timeToTarget > lastTime) {
                fleets++;
                lastTime = timeToTarget;
            }
        }

        return fleets;
    }
};
