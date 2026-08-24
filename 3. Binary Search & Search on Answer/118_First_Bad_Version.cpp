// Link: https://leetcode.com/problems/first-bad-version/

#include <iostream>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int version);

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Answer)
// ==========================================
// Time Complexity  : O(log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize low = 1, high = n, ans = n.
2. While low <= high:
     mid = low + (high - low) / 2
     if isBadVersion(mid):
         ans = mid // Potential first bad version
         high = mid - 1
     else:
         low = mid + 1
3. Return ans.
*/

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isBadVersion(mid)) {
                ans = mid;
                high = mid - 1; // Look for earlier bad versions on the left
            } else {
                low = mid + 1; // First bad version is to the right
            }
        }

        return ans;
    }
};
