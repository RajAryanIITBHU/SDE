// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Min-Heap of Size K)
// ==========================================
// Time Complexity  : Constructor: O(n log k), add: O(log k)
// Space Complexity : O(k)
/*
PSEUDOCODE:
1. Maintain min-heap priority_queue pq of size k.
2. In add(val):
     pq.push(val)
     if pq.size() > k:
         pq.pop()
     return pq.top()
*/

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kSize;

public:
    KthLargest(int k, vector<int>& nums) {
        kSize = k;
        for (int num : nums) {
            pq.push(num);
            if ((int)pq.size() > kSize) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        if ((int)pq.size() > kSize) {
            pq.pop();
        }
        return pq.top();
    }
};
