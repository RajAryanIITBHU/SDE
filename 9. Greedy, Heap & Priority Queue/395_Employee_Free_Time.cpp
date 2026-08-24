// Link: https://leetcode.com/problems/employee-free-time/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

// ==========================================
// 1. OPTIMAL APPROACH (Interval Flattening + Merging Gaps)
// ==========================================
// Time Complexity  : O(N log N), where N is total intervals
// Space Complexity : O(N)
/*
PSEUDOCODE:
1. Flatten all employee intervals into a single vector allIntervals.
2. Sort allIntervals by start time.
3. mergedEnd = allIntervals[0].end, vector<Interval> freeTime.
4. For i from 1 to allIntervals.size() - 1:
     if allIntervals[i].start > mergedEnd:
         freeTime.push_back(Interval(mergedEnd, allIntervals[i].start))
     mergedEnd = max(mergedEnd, allIntervals[i].end)
5. Return freeTime.
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> allIntervals;
        for (const auto& emp : schedule) {
            for (const auto& iv : emp) {
                allIntervals.push_back(iv);
            }
        }

        sort(allIntervals.begin(), allIntervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        vector<Interval> freeTime;
        int mergedEnd = allIntervals[0].end;

        for (int i = 1; i < (int)allIntervals.size(); i++) {
            // Gap found between mergedEnd and next interval start
            if (allIntervals[i].start > mergedEnd) {
                freeTime.push_back(Interval(mergedEnd, allIntervals[i].start));
            }
            mergedEnd = max(mergedEnd, allIntervals[i].end);
        }

        return freeTime;
    }
};
