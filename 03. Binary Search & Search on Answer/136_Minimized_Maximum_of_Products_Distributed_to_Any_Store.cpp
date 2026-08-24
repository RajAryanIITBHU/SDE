// Link: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Store Quota)
// ==========================================
// Time Complexity  : O(m * log(max(quantities)))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper canDistribute(quota):
     storesNeeded = 0
     For each q in quantities:
         storesNeeded += (q + quota - 1) / quota // ceil(q / quota)
     return storesNeeded <= n
2. Search range: low = 1, high = max(quantities), ans = high.
3. While low <= high:
     mid = low + (high - low) / 2
     if canDistribute(mid):
         ans = mid
         high = mid - 1
     else:
         low = mid + 1
4. Return ans.
*/

class Solution {
private:
    bool canDistribute(vector<int>& quantities, int n, int quota) {
        long long storesNeeded = 0;
        for (int q : quantities) {
            storesNeeded += (q + quota - 1) / quota; // Ceiling division
        }
        return storesNeeded <= n;
    }

public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canDistribute(quantities, n, mid)) {
                ans = mid;
                high = mid - 1; // Minimize maximum
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
