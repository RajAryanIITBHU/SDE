// Link: https://leetcode.com/problems/find-k-closest-elements/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search for Window Start Index)
// ==========================================
// Time Complexity  : O(log(n - k) + k)
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. Search for the best starting index of the window of size k: low = 0, high = n - k.
2. While low < high:
     mid = low + (high - low) / 2
     // Compare distance of element at mid vs element at (mid + k) to x
     if x - arr[mid] > arr[mid + k] - x:
         low = mid + 1 // arr[mid + k] is strictly closer than arr[mid]
     else:
         high = mid
3. Return vector(arr.begin() + low, arr.begin() + low + k).
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = (int)arr.size() - k;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Check which endpoint is closer to x
            if (x - arr[mid] > arr[mid + k] - x) {
                low = mid + 1; // Window should move right
            } else {
                high = mid; // Window is at mid or should move left
            }
        }

        return vector<int>(arr.begin() + low, arr.begin() + low + k);
    }
};
