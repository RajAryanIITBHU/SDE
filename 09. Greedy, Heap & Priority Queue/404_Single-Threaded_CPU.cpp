// Link: https://leetcode.com/problems/single-threaded-cpu/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Task Sorting + Min-Heap of Available Tasks)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Augment tasks with original indices: sortedTasks = {enqueueTime, processingTime, originalIndex}.
2. Sort sortedTasks by enqueueTime.
3. Min-heap pq storing {processingTime, originalIndex}.
4. time = 0, taskIdx = 0, vector<int> ans.
5. While taskIdx < n || !pq.empty():
     if pq.empty() && time < sortedTasks[taskIdx][0]:
         time = sortedTasks[taskIdx][0] // Fast-forward time to next task arrival
     While taskIdx < n && sortedTasks[taskIdx][0] <= time:
         pq.push({sortedTasks[taskIdx][1], sortedTasks[taskIdx][2]})
         taskIdx++
     {procTime, origIdx} = pq.top(), pq.pop()
     time += procTime
     ans.push_back(origIdx)
6. Return ans.
*/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> sortedTasks;

        for (int i = 0; i < n; i++) {
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(sortedTasks.begin(), sortedTasks.end());

        // Min-heap: {processingTime, originalIndex}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;

        long long time = 0;
        int i = 0;

        while (i < n || !pq.empty()) {
            if (pq.empty() && time < sortedTasks[i][0]) {
                time = sortedTasks[i][0];
            }

            while (i < n && sortedTasks[i][0] <= time) {
                pq.push({sortedTasks[i][1], sortedTasks[i][2]});
                i++;
            }

            auto [procTime, origIdx] = pq.top();
            pq.pop();

            time += procTime;
            ans.push_back(origIdx);
        }

        return ans;
    }
};
