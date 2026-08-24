// Link: https://leetcode.com/problems/find-k-th-smallest-pair-distance/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sorting + Binary Search on Distance + Two Pointers)
// ==========================================
// Time Complexity  : O(n log n + n * log(max_dist))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Sort nums.
2. Helper countPairsWithDistanceLessThanOrEqual(mid):
     count = 0, left = 0
     For right from 0 to n-1:
         While nums[right] - nums[left] > mid:
             left++
         count += (right - left)
     return count
3. low = 0, high = nums[n-1] - nums[0], ans = high.
4. While low <= high:
     mid = low + (high - low) / 2
     if countPairsWithDistanceLessThanOrEqual(mid) >= k:
         ans = mid
         high = mid - 1
     else:
         low = mid + 1
5. Return ans.
*/

class Solution {
private:
    int countPairs(vector<int>& nums, int mid) {
        int count = 0;
        int left = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            while (nums[right] - nums[left] > mid) {
                left++;
            }
            count += (right - left);
        }

        return count;
    }

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back() - nums.front();
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (countPairs(nums, mid) >= k) {
                ans = mid;
                high = mid - 1; // Try smaller distance
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
