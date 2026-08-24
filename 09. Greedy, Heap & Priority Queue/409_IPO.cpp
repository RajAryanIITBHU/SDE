// Link: https://leetcode.com/problems/ipo/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sorting by Capital + Max-Heap of Available Profits)
// ==========================================
// Time Complexity  : O(n log n + k log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Combine capital and profits into projects vector: {capital, profit}.
2. Sort projects by capital in ascending order.
3. Max-heap pq of available profits.
4. projectIdx = 0, currentCapital = w.
5. For step from 1 to k:
     While projectIdx < n && projects[projectIdx].first <= currentCapital:
         pq.push(projects[projectIdx].second)
         projectIdx++
     if pq.empty() break // No affordable projects left
     currentCapital += pq.top(), pq.pop()
6. Return currentCapital.
*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);

        for (int i = 0; i < n; i++) {
            projects[i] = {capital[i], profits[i]};
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> pq; // Max-heap of profits
        int i = 0;

        for (int step = 0; step < k; step++) {
            // Push all affordable projects into max-heap
            while (i < n && projects[i].first <= w) {
                pq.push(projects[i].second);
                i++;
            }

            if (pq.empty()) {
                break;
            }

            w += pq.top(); // Choose project with max profit
            pq.pop();
        }

        return w;
    }
};
