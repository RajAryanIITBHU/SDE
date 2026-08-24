// Link: https://www.geeksforgeeks.org/problems/geeks-training/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (2D / Space-Optimized Dynamic Programming)
// ==========================================
// Time Complexity  : O(n * 4 * 3) = O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
dp[task] represents the maximum points on previous day given task was performed.
1. prev[0] = max(arr[0][1], arr[0][2])
   prev[1] = max(arr[0][0], arr[0][2])
   prev[2] = max(arr[0][0], arr[0][1])
   prev[3] = max({arr[0][0], arr[0][1], arr[0][2]})
2. For day from 1 to n-1:
     For last from 0 to 3:
         curr[last] = 0
         For task from 0 to 2:
             if task != last:
                 curr[last] = max(curr[last], arr[day][task] + prev[task])
     prev = curr
3. Return prev[3].
*/

class Solution {
public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<int> prev(4, 0);

        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max({arr[0][0], arr[0][1], arr[0][2]});

        for (int day = 1; day < n; day++) {
            vector<int> curr(4, 0);

            for (int last = 0; last < 4; last++) {
                curr[last] = 0;
                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        int point = arr[day][task] + prev[task];
                        curr[last] = max(curr[last], point);
                    }
                }
            }
            prev = curr;
        }

        return prev[3];
    }
};
