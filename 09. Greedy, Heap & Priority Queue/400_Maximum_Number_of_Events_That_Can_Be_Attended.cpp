// Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Day Simulation + Min-Heap of End Days)
// ==========================================
// Time Complexity  : O(N log N + maxDay log N)
// Space Complexity : O(N)
/*
PSEUDOCODE:
1. Sort events by startDay.
2. Min-heap pq storing endDay of events currently active.
3. eventsAttended = 0, eventIdx = 0, n = events.size().
4. For day from 1 to 100000:
     // Add all events starting on or before day
     While eventIdx < n && events[eventIdx][0] <= day:
         pq.push(events[eventIdx][1])
         eventIdx++
     // Remove expired events
     While !pq.empty() && pq.top() < day:
         pq.pop()
     // Attend event ending earliest
     if !pq.empty():
         pq.pop()
         eventsAttended++
     if eventIdx == n && pq.empty() break
5. Return eventsAttended.
*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap of event end days
        int attended = 0;
        int i = 0;
        int n = events.size();

        for (int day = 1; day <= 100000; day++) {
            // Push all events starting on current day
            while (i < n && events[i][0] <= day) {
                pq.push(events[i][1]);
                i++;
            }

            // Discard events that have already ended
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Attend the event that closes earliest
            if (!pq.empty()) {
                pq.pop();
                attended++;
            }

            if (i == n && pq.empty()) {
                break;
            }
        }

        return attended;
    }
};
