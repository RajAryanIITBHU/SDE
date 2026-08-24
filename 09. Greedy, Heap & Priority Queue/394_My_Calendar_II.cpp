// Link: https://leetcode.com/problems/my-calendar-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Overlapping Intervals Tracking: Single & Double Bookings)
// ==========================================
// Time Complexity  : O(n) per book call
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain singleBookings list and doubleBookings (overlaps) list.
2. For each (s, e) in doubleBookings:
     if max(start, s) < min(end, e) return false (would cause triple booking)
3. For each (s, e) in singleBookings:
     if max(start, s) < min(end, e):
         doubleBookings.push_back({max(start, s), min(end, e)})
4. singleBookings.push_back({start, end})
5. Return true.
*/

class MyCalendarTwo {
private:
    vector<pair<int, int>> singleBookings;
    vector<pair<int, int>> doubleBookings;

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        // Check if overlaps with any existing double booking -> would create triple booking
        for (auto& db : doubleBookings) {
            if (max(start, db.first) < min(end, db.second)) {
                return false;
            }
        }

        // Add overlaps with single bookings into double bookings
        for (auto& sb : singleBookings) {
            if (max(start, sb.first) < min(end, sb.second)) {
                doubleBookings.push_back({max(start, sb.first), min(end, sb.second)});
            }
        }

        singleBookings.push_back({start, end});
        return true;
    }
};
