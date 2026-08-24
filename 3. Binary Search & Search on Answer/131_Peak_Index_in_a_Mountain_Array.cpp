// Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Slope)
// ==========================================
// Time Complexity  : O(log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. low = 0, high = n - 1.
2. While low < high:
     mid = low + (high - low) / 2
     if arr[mid] < arr[mid + 1]:
         low = mid + 1 // Going up, peak is to the right
     else:
         high = mid // Going down, peak is at mid or to the left
3. Return low.
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = (int)arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};
