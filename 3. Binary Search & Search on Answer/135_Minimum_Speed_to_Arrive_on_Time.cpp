// Link: https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Speed)
// ==========================================
// Time Complexity  : O(n * log(1e7))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If hour <= dist.size() - 1 return -1 (each ride takes at least 1 hour except the last).
2. Helper timeTaken(speed):
     totalTime = 0.0
     For i from 0 to n-2:
         totalTime += (dist[i] + speed - 1) / speed // Integer ceil
     totalTime += (double)dist[n-1] / speed // Last train exact fraction
     return totalTime <= hour
3. low = 1, high = 1e7, ans = -1.
4. While low <= high:
     mid = low + (high - low) / 2
     if timeTaken(mid):
         ans = mid
         high = mid - 1
     else:
         low = mid + 1
5. Return ans.
*/

class Solution {
private:
    bool timeTaken(vector<int>& dist, double hour, int speed) {
        double totalTime = 0.0;
        int n = dist.size();

        for (int i = 0; i < n - 1; i++) {
            totalTime += (dist[i] + speed - 1) / speed; // Ceiling for all but last train
        }
        totalTime += (double)dist[n - 1] / speed; // Exact time for last train

        return totalTime <= hour;
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour <= (double)(n - 1)) return -1;

        int low = 1;
        int high = 1e7;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (timeTaken(dist, hour, mid)) {
                ans = mid;
                high = mid - 1; // Try smaller speed
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
