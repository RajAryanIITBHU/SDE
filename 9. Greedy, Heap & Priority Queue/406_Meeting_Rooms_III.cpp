// Link: https://leetcode.com/problems/meeting-rooms-iii/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Dual Min-Heaps: Free Rooms & Busy Rooms)
// ==========================================
// Time Complexity  : O(M log M + M log N), where M = meetings, N = rooms
// Space Complexity : O(N)
/*
PSEUDOCODE:
1. Sort meetings by start time.
2. Min-heap freeRooms initialized with 0..n-1.
3. Min-heap busyRooms storing {endTime, roomNumber}.
4. roomCount array of size n with 0.
5. For each meeting [start, end]:
     duration = end - start
     // Free all rooms whose meetings finished on or before start
     While !busyRooms.empty() && busyRooms.top().first <= start:
         freeRooms.push(busyRooms.top().second)
         busyRooms.pop()
     if !freeRooms.empty():
         room = freeRooms.top(), freeRooms.pop()
         busyRooms.push({end, room})
         roomCount[room]++
     else:
         // Wait for earliest ending room
         {earliestEnd, room} = busyRooms.top(), busyRooms.pop()
         busyRooms.push({earliestEnd + duration, room})
         roomCount[room]++
6. Find room with max meetings held (tie-breaker: lowest room index).
7. Return bestRoom.
*/

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; i++) {
            freeRooms.push(i);
        }

        // Min-heap: {endTime, roomNumber}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyRooms;
        vector<int> roomCount(n, 0);

        for (auto& m : meetings) {
            long long start = m[0];
            long long end = m[1];
            long long duration = end - start;

            // Free finished rooms
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                busyRooms.push({end, room});
                roomCount[room]++;
            } else {
                auto [earliestEnd, room] = busyRooms.top();
                busyRooms.pop();
                busyRooms.push({earliestEnd + duration, room});
                roomCount[room]++;
            }
        }

        int maxMeetings = 0;
        int bestRoom = 0;

        for (int i = 0; i < n; i++) {
            if (roomCount[i] > maxMeetings) {
                maxMeetings = roomCount[i];
                bestRoom = i;
            }
        }

        return bestRoom;
    }
};
