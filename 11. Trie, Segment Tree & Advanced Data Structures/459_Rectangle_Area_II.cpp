// Link: https://leetcode.com/problems/rectangle-area-ii/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sweep-Line with Y-Coordinate Merging)
// ==========================================
// Time Complexity  : O(n^2 log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Deconstruct each rectangle [x1, y1, x2, y2] into vertical events:
     Start event at x1: {x1, y1, y2, +1}
     End event at x2: {x2, y1, y2, -1}
2. Sort events by x coordinate.
3. Maintain active intervals in y-dimension.
4. Total area = sum of (x_curr - x_prev) * totalYCoveredLength mod (1e9+7).
5. Return totalArea.
*/

class Solution {
private:
    struct Event {
        int x;
        int y1;
        int y2;
        int type; // +1 start, -1 end
    };

    long long calculateYLength(const vector<pair<int, int>>& activeIntervals) {
        if (activeIntervals.empty()) return 0;

        vector<pair<int, int>> intervals = activeIntervals;
        sort(intervals.begin(), intervals.end());

        long long totalY = 0;
        int curStart = intervals[0].first;
        int curEnd = intervals[0].second;

        for (int i = 1; i < (int)intervals.size(); i++) {
            if (intervals[i].first > curEnd) {
                totalY += (curEnd - curStart);
                curStart = intervals[i].first;
                curEnd = intervals[i].second;
            } else {
                curEnd = max(curEnd, intervals[i].second);
            }
        }

        totalY += (curEnd - curStart);
        return totalY;
    }

public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int MOD = 1e9 + 7;
        vector<Event> events;

        for (const auto& r : rectangles) {
            events.push_back({r[0], r[1], r[3], 1});  // Left edge
            events.push_back({r[2], r[1], r[3], -1}); // Right edge
        }

        sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
            return a.x < b.x;
        });

        vector<pair<int, int>> activeIntervals;
        long long totalArea = 0;
        int prevX = events[0].x;

        for (const auto& ev : events) {
            int currX = ev.x;

            if (currX > prevX) {
                long long yLength = calculateYLength(activeIntervals);
                totalArea = (totalArea + (long long)(currX - prevX) * yLength) % MOD;
                prevX = currX;
            }

            if (ev.type == 1) {
                activeIntervals.push_back({ev.y1, ev.y2});
            } else {
                for (auto it = activeIntervals.begin(); it != activeIntervals.end(); ++it) {
                    if (it->first == ev.y1 && it->second == ev.y2) {
                        activeIntervals.erase(it);
                        break;
                    }
                }
            }
        }

        return totalArea;
    }
};
