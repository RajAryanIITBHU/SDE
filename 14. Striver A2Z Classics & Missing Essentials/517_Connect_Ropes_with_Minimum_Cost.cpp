// Link: https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Min-Heap Greedy Merge)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Min-heap pq initialized with all rope lengths.
2. totalCost = 0.
3. While pq.size() > 1:
     first = pq.top(), pq.pop()
     second = pq.top(), pq.pop()
     cost = first + second
     totalCost += cost
     pq.push(cost)
4. Return totalCost.
*/

class Solution {
public:
    long long minCost(vector<long long>& arr) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(arr.begin(), arr.end());
        long long totalCost = 0;

        while (pq.size() > 1) {
            long long first = pq.top();
            pq.pop();

            long long second = pq.top();
            pq.pop();

            long long cost = first + second;
            totalCost += cost;

            pq.push(cost);
        }

        return totalCost;
    }
};
