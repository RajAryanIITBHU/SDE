// Link: https://leetcode.com/problems/meeting-rooms-ii/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BETTER APPROACH (Min-Heap for Active Rooms)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Sort intervals by start time.
2. Initialize min-heap pq to track end times of active meetings.
3. For each interval:
     if !pq.empty() && pq.top() <= interval.start:
         pq.pop() // reuse room
     pq.push(interval.end)
4. Return pq.size().
*/

class SolutionBetter {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        sort(intervals.begin(), intervals.end());

        // Min-heap to store end times of meetings
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++) {
            // If the earliest finishing meeting has ended, free that room
            if (!pq.empty() && pq.top() <= intervals[i][0]) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }

        return pq.size();
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Two Pointers / Chronological Order)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Extract start times and end times into separate arrays starts and ends.
2. Sort starts and ends independently.
3. Use pointers i = 0 (starts) and j = 0 (ends).
4. For i from 0 to n-1:
     if starts[i] < ends[j]:
         rooms++
     else:
         j++ // meeting ended, room released
5. Return rooms.
*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        vector<int> startTimes(n);
        vector<int> endTimes(n);

        for (int i = 0; i < n; i++) {
            startTimes[i] = intervals[i][0];
            endTimes[i] = intervals[i][1];
        }

        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int rooms = 0;
        int j = 0; // Pointer for end times

        for (int i = 0; i < n; i++) {
            // If a meeting starts before the earliest ending meeting finishes, need a new room
            if (startTimes[i] < endTimes[j]) {
                rooms++;
            } else {
                j++; // Room reused
            }
        }

        return rooms;
    }
};
