// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Min-Heap of Size K)
// ==========================================
// Time Complexity  : O(n log k)
// Space Complexity : O(k)
/*
PSEUDOCODE:
1. Initialize min-heap priority_queue pq.
2. For each num in nums:
     pq.push(num)
     if pq.size() > k:
         pq.pop()
3. Return pq.top().
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap

        for (int num : nums) {
            pq.push(num);
            if ((int)pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};
