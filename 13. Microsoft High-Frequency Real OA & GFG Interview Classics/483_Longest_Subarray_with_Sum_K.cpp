// Link: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Prefix Sum with Hash Map)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. sumMap: stores first occurrence index of prefix sums.
2. PS = 0, maxLen = 0.
3. For i from 0 to n-1:
     PS += arr[i]
     if PS == k:
         maxLen = i + 1
     if sumMap.find(PS - k) != sumMap.end():
         maxLen = max(maxLen, i - sumMap[PS - k])
     if sumMap.find(PS) == sumMap.end():
         sumMap[PS] = i
4. Return maxLen.
*/

class Solution {
public:
    int lenOfLongSubarr(vector<int>& arr, int k) {
        unordered_map<long long, int> sumMap;
        long long PS = 0;
        int maxLen = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            PS += arr[i];

            if (PS == k) {
                maxLen = i + 1;
            }

            if (sumMap.find(PS - k) != sumMap.end()) {
                maxLen = max(maxLen, i - sumMap[PS - k]);
            }

            // Only store the first occurrence of prefix sum to maximize length
            if (sumMap.find(PS) == sumMap.end()) {
                sumMap[PS] = i;
            }
        }

        return maxLen;
    }
};
