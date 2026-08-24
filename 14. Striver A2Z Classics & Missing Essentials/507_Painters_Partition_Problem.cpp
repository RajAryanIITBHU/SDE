// Link: https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Maximum Time)
// ==========================================
// Time Complexity  : O(n log(sum(arr)))
// Space Complexity : O(1)
/*
PSEUDOCODE:
Identical formulation to Book Allocation Problem:
1. low = max(arr), high = sum(arr).
2. Helper canPaint(maxTime, arr, k):
     painters = 1, currTime = 0
     For board in arr:
         if currTime + board > maxTime:
             painters++
             currTime = board
         else:
             currTime += board
     return painters <= k
3. BS in [low, high]:
     mid = low + (high - low) / 2
     if canPaint(mid): ans = mid, high = mid - 1
     else: low = mid + 1
4. Return ans.
*/

class Solution {
private:
    bool canPaint(long long maxTime, const vector<int>& arr, int k) {
        int painters = 1;
        long long currentLoad = 0;

        for (int board : arr) {
            if (currentLoad + board > maxTime) {
                painters++;
                currentLoad = board;
            } else {
                currentLoad += board;
            }
        }

        return painters <= k;
    }

public:
    long long minTime(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end());
        long long high = 0;
        for (int x : arr) high += x;

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canPaint(mid, arr, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
