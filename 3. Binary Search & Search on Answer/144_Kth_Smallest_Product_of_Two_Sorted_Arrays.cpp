// Link: https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Product Value)
// ==========================================
// Time Complexity  : O((n + m) * log(2 * 1e10))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper countLessEqual(nums1, nums2, mid):
     count = 0
     For each x in nums1:
         if x > 0 -> count += upper_bound(nums2, floor(mid / x)) - nums2.begin()
         if x < 0 -> count += nums2.end() - lower_bound(nums2, ceil(mid / x))
         if x == 0 -> if mid >= 0, count += nums2.size()
     return count
2. Search range: low = -1e10, high = 1e10, ans = high.
3. While low <= high:
     mid = low + (high - low) / 2
     if countLessEqual(nums1, nums2, mid) >= k:
         ans = mid
         high = mid - 1
     else:
         low = mid + 1
4. Return ans.
*/

class Solution {
private:
    long long countPairs(vector<int>& nums1, vector<int>& nums2, long long mid) {
        long long count = 0;
        int m = nums2.size();

        for (long long x : nums1) {
            if (x > 0) {
                // x * y <= mid  =>  y <= floor(mid / x)
                long long target = (mid >= 0) ? (mid / x) : ((mid - x + 1) / x);
                auto it = upper_bound(nums2.begin(), nums2.end(), target);
                count += (it - nums2.begin());
            } else if (x < 0) {
                // x * y <= mid  =>  y >= ceil(mid / x)
                long long target = (mid >= 0) ? ((mid + (-x) - 1) / x) : (mid / x);
                auto it = lower_bound(nums2.begin(), nums2.end(), target);
                count += (nums2.end() - it);
            } else {
                if (mid >= 0) {
                    count += m;
                }
            }
        }

        return count;
    }

public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low = -1e10;
        long long high = 1e10;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countPairs(nums1, nums2, mid) >= k) {
                ans = mid;
                high = mid - 1; // Try smaller candidate
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
