// Link: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/

#include <iostream>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Value Range)
// ==========================================
// Time Complexity  : O(m * log(m * n))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper countLessEqual(mid):
     count = 0
     For row from 1 to m:
         count += min(mid / row, n)
     return count
2. low = 1, high = m * n, ans = high.
3. While low <= high:
     mid = low + (high - low) / 2
     if countLessEqual(mid) >= k:
         ans = mid
         high = mid - 1
     else:
         low = mid + 1
4. Return ans.
*/

class Solution {
private:
    int countLessEqual(int m, int n, int mid) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += min(mid / i, n);
        }
        return count;
    }

public:
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n;
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (countLessEqual(m, n, mid) >= k) {
                ans = mid;
                high = mid - 1; // Try smaller candidate
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
