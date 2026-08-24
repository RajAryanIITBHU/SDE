// Link: https://leetcode.com/problems/furthest-building-you-can-reach/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Min-Heap for Ladders on Largest Climbs)
// ==========================================
// Time Complexity  : O(n log(ladders))
// Space Complexity : O(ladders)
/*
PSEUDOCODE:
1. Min-heap pq storing heights of climbs where ladders are allocated.
2. For i from 0 to heights.size() - 2:
     climb = heights[i + 1] - heights[i]
     if climb > 0:
         pq.push(climb)
         if pq.size() > ladders:
             // Smallest climb must use bricks instead
             bricks -= pq.top(), pq.pop()
             if bricks < 0 return i
3. Return heights.size() - 1.
*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap storing ladder climb heights

        for (int i = 0; i < (int)heights.size() - 1; i++) {
            int climb = heights[i + 1] - heights[i];

            if (climb > 0) {
                pq.push(climb);

                // If we need more climbs than ladders available, use bricks for the smallest climb
                if ((int)pq.size() > ladders) {
                    bricks -= pq.top();
                    pq.pop();

                    if (bricks < 0) {
                        return i;
                    }
                }
            }
        }

        return heights.size() - 1;
    }
};
