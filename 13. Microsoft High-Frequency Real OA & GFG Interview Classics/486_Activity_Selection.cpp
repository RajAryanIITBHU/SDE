// Link: https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Finish Time Sorting)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Combine start and end into activities: {endTime, startTime}.
2. Sort activities by endTime in ascending order.
3. selectedCount = 1, lastEndTime = activities[0].first.
4. For i from 1 to n-1:
     if activities[i].second > lastEndTime:
         selectedCount++
         lastEndTime = activities[i].first
5. Return selectedCount.
*/

class Solution {
public:
    int activitySelection(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> activities(n);

        for (int i = 0; i < n; i++) {
            activities[i] = {end[i], start[i]};
        }

        // Sort greedily by earliest finish time
        sort(activities.begin(), activities.end());

        int count = 1;
        int lastEndTime = activities[0].first;

        for (int i = 1; i < n; i++) {
            if (activities[i].second > lastEndTime) {
                count++;
                lastEndTime = activities[i].first;
            }
        }

        return count;
    }
};
