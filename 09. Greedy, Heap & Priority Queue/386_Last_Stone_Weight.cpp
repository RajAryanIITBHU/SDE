// Link: https://leetcode.com/problems/last-stone-weight/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Max-Heap Simulation)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Max-heap priority_queue pq initialized with stones.
2. While pq.size() > 1:
     y = pq.top(), pq.pop()
     x = pq.top(), pq.pop()
     if y != x:
         pq.push(y - x)
3. Return pq.empty() ? 0 : pq.top().
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if (y != x) {
                pq.push(y - x);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};
