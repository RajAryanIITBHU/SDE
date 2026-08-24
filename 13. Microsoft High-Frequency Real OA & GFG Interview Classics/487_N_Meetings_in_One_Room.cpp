// Link: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Finish Time Interval Scheduling)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Combine start and end into meetings: {endTime, startTime}.
2. Sort meetings by endTime ascending.
3. meetingCount = 1, currentEndTime = meetings[0].first.
4. For i from 1 to n-1:
     if meetings[i].second > currentEndTime:
         meetingCount++
         currentEndTime = meetings[i].first
5. Return meetingCount.
*/

class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> meetings(n);

        for (int i = 0; i < n; i++) {
            meetings[i] = {end[i], start[i]};
        }

        sort(meetings.begin(), meetings.end());

        int count = 1;
        int currentEndTime = meetings[0].first;

        for (int i = 1; i < n; i++) {
            if (meetings[i].second > currentEndTime) {
                count++;
                currentEndTime = meetings[i].first;
            }
        }

        return count;
    }
};
