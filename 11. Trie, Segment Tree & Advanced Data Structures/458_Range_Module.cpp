// Link: https://leetcode.com/problems/range-module/

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Ordered Map of Disjoint Intervals)
// ==========================================
// Time Complexity  : addRange, removeRange: O(k log n) where k is overlapped intervals count, queryRange: O(log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
Maintain map<int, int> intervals (left -> right) of non-overlapping intervals.
1. addRange(left, right):
     find first interval with right' >= left, merge all overlapping intervals until left' > right.
2. queryRange(left, right):
     find interval covering [left, right], return true if exists.
3. removeRange(left, right):
     split overlapping intervals, remove covered parts.
*/

class RangeModule {
private:
    map<int, int> intervals; // left -> right

public:
    RangeModule() {}

    void addRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it != intervals.begin()) {
            auto prev = std::prev(it);
            if (prev->second >= left) {
                it = prev;
            }
        }

        while (it != intervals.end() && it->first <= right) {
            left = min(left, it->first);
            right = max(right, it->second);
            it = intervals.erase(it);
        }

        intervals[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it == intervals.begin()) return false;
        auto prev = std::prev(it);
        return prev->first <= left && prev->second >= right;
    }

    void removeRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it != intervals.begin()) {
            auto prev = std::prev(it);
            if (prev->second >= left) {
                it = prev;
            }
        }

        vector<pair<int, int>> toInsert;

        while (it != intervals.end() && it->first < right) {
            if (it->first < left) {
                toInsert.push_back({it->first, left});
            }
            if (it->second > right) {
                toInsert.push_back({right, it->second});
            }
            it = intervals.erase(it);
        }

        for (const auto& p : toInsert) {
            intervals[p.first] = p.second;
        }
    }
};
