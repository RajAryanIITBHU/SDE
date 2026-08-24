// Link: https://leetcode.com/problems/minimize-max-distance-to-gas-station/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Floating Point Distance)
// ==========================================
// Time Complexity  : O(n * log((max_dist) / 1e-6))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper canPlaceStations(dist):
     addedStations = 0
     For i from 0 to n-2:
         addedStations += (int)((stations[i+1] - stations[i]) / dist)
     return addedStations <= k
2. Search range: low = 0.0, high = stations[n-1] - stations[0].
3. While high - low > 1e-6:
     mid = low + (high - low) / 2.0
     if canPlaceStations(mid):
         high = mid
     else:
         low = mid
4. Return low.
*/

class Solution {
private:
    bool canPlaceStations(vector<int>& stations, int k, double dist) {
        int addedStations = 0;
        int n = stations.size();

        for (int i = 0; i < n - 1; i++) {
            addedStations += (int)((stations[i + 1] - stations[i]) / dist);
        }

        return addedStations <= k;
    }

public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double low = 0.0;
        double high = stations.back() - stations.front();
        double eps = 1e-6;

        while (high - low > eps) {
            double mid = low + (high - low) / 2.0;

            if (canPlaceStations(stations, k, mid)) {
                high = mid; // Can achieve max distance <= mid, try even smaller
            } else {
                low = mid;
            }
        }

        return low;
    }
};
