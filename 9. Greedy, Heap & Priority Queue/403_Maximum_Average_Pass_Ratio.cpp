// Link: https://leetcode.com/problems/maximum-average-pass-ratio/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Max-Heap on Marginal Pass Ratio Gain)
// ==========================================
// Time Complexity  : O((n + extraStudents) * log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Helper gain(pass, total) = ((double)(pass + 1) / (total + 1)) - ((double)pass / total).
2. Max-heap pq storing {gain(pass, total), {pass, total}}.
3. For student from 1 to extraStudents:
     {g, {p, t}} = pq.top(), pq.pop()
     p++, t++
     pq.push({gain(p, t), {p, t}})
4. Total ratio = sum of (double)p / t for all classes.
5. Return totalRatio / n.
*/

class Solution {
private:
    double getGain(int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Max-heap: {marginalGain, {pass, total}}
        priority_queue<pair<double, pair<int, int>>> pq;

        for (auto& cls : classes) {
            pq.push({getGain(cls[0], cls[1]), {cls[0], cls[1]}});
        }

        while (extraStudents > 0) {
            auto [g, pt] = pq.top();
            pq.pop();

            int p = pt.first + 1;
            int t = pt.second + 1;
            pq.push({getGain(p, t), {p, t}});

            extraStudents--;
        }

        double totalRatio = 0.0;
        while (!pq.empty()) {
            auto pt = pq.top().second;
            totalRatio += (double)pt.first / pt.second;
            pq.pop();
        }

        return totalRatio / classes.size();
    }
};
