// Link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Two-Pointer Timeline Simulation)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Sort arr (arrival times) and dep (departure times) individually.
2. i = 0, j = 0, currentPlatforms = 0, maxPlatforms = 0.
3. While i < n && j < n:
     if arr[i] <= dep[j]:
         currentPlatforms++
         i++
     else:
         currentPlatforms--
         j++
     maxPlatforms = max(maxPlatforms, currentPlatforms)
4. Return maxPlatforms.
*/

class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int n = arr.size();
        int i = 0;
        int j = 0;
        int currentPlatforms = 0;
        int maxPlatforms = 0;

        while (i < n && j < n) {
            // Train arrives before or at the departure of the current earliest departure
            if (arr[i] <= dep[j]) {
                currentPlatforms++;
                i++;
            } else {
                currentPlatforms--;
                j++;
            }

            maxPlatforms = max(maxPlatforms, currentPlatforms);
        }

        return maxPlatforms;
    }
};
