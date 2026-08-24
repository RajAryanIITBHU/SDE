// Link: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Dual Min-Heaps: Available Chairs & Busy Chairs)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Target arrival time = times[targetFriend][0].
2. Sort friends by arrival times: {arrival, leave, friendIndex}.
3. Min-heap availableChairs initialized with chairs 0..n-1.
4. Min-heap busyChairs storing {leaveTime, chairNumber}.
5. For each friend:
     // Free all chairs where friend has left before current arrival
     While !busyChairs.empty() && busyChairs.top().first <= arrival:
         availableChairs.push(busyChairs.top().second)
         busyChairs.pop()
     assignedChair = availableChairs.top(), availableChairs.pop()
     if friendIndex == targetFriend:
         return assignedChair
     busyChairs.push({leave, assignedChair})
6. Return 0.
*/

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<vector<int>> events;

        for (int i = 0; i < n; i++) {
            events.push_back({times[i][0], times[i][1], i});
        }

        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; i++) {
            availableChairs.push(i);
        }

        // Min-heap: {leavingTime, chairNumber}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busyChairs;

        for (auto& ev : events) {
            int arrival = ev[0];
            int leaving = ev[1];
            int friendIdx = ev[2];

            // Free occupied chairs
            while (!busyChairs.empty() && busyChairs.top().first <= arrival) {
                availableChairs.push(busyChairs.top().second);
                busyChairs.pop();
            }

            int chair = availableChairs.top();
            availableChairs.pop();

            if (friendIdx == targetFriend) {
                return chair;
            }

            busyChairs.push({leaving, chair});
        }

        return 0;
    }
};
