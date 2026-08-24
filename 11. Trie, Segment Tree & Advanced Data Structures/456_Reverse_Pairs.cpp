// Link: https://leetcode.com/problems/reverse-pairs/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Merge Sort Count Inversion)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
Condition: i < j and nums[i] > 2 * nums[j].
1. Helper mergeSort(left, right, nums, temp):
     if left >= right return 0
     mid = left + (right - left) / 2
     count = mergeSort(left, mid, nums, temp) + mergeSort(mid + 1, right, nums, temp)
     // Count reverse pairs
     j = mid + 1
     For i from left to mid:
         While j <= right && (long long)nums[i] > 2LL * nums[j]:
             j++
         count += (j - (mid + 1))
     // Standard merge
     Merge sorted halves into temp, copy back to nums.
     return count
2. Return mergeSort(0, nums.size() - 1, nums, temp).
*/

class Solution {
private:
    int mergeSort(int left, int right, vector<int>& nums, vector<int>& temp) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        int count = mergeSort(left, mid, nums, temp) + mergeSort(mid + 1, right, nums, temp);

        // Count pairs where nums[i] > 2 * nums[j]
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Standard merge
        int i = left;
        j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) temp[k++] = nums[i++];
        while (j <= right) temp[k++] = nums[j++];

        for (int p = left; p <= right; p++) {
            nums[p] = temp[p];
        }

        return count;
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        return mergeSort(0, n - 1, nums, temp);
    }
};
