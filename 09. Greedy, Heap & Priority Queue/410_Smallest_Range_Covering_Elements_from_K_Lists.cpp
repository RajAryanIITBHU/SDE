// Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Element state in K lists: {value, row, col}
struct Node {
    int val;
    int row;
    int col;
    bool operator>(const Node& other) const {
        return val > other.val;
    }
};

// ==========================================
// 1. OPTIMAL APPROACH (K-Way Merge Min-Heap + Max Tracker)
// ==========================================
// Time Complexity  : O(N log k), where N is total elements across all lists
// Space Complexity : O(k)
/*
PSEUDOCODE:
1. Min-heap pq storing Node {val, row, col}.
2. currentMax = INT_MIN.
3. Push first element of each of the k lists into pq, update currentMax.
4. rangeStart = 0, rangeEnd = INT_MAX.
5. While pq.size() == k:
     curr = pq.top(), pq.pop()
     if (currentMax - curr.val) < (rangeEnd - rangeStart):
         rangeStart = curr.val
         rangeEnd = currentMax
     if curr.col + 1 < nums[curr.row].size():
         nextVal = nums[curr.row][curr.col + 1]
         currentMax = max(currentMax, nextVal)
         pq.push({nextVal, curr.row, curr.col + 1})
     else:
         break // One list exhausted, cannot cover all lists anymore
6. Return {rangeStart, rangeEnd}.
*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<Node, vector<Node>, greater<Node>> pq; // Min-heap

        int currentMax = INT_MIN;

        for (int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }

        int rangeStart = 0;
        int rangeEnd = INT_MAX;

        while ((int)pq.size() == k) {
            Node curr = pq.top();
            pq.pop();

            if (currentMax - curr.val < rangeEnd - rangeStart) {
                rangeStart = curr.val;
                rangeEnd = currentMax;
            }

            if (curr.col + 1 < (int)nums[curr.row].size()) {
                int nextVal = nums[curr.row][curr.col + 1];
                currentMax = max(currentMax, nextVal);
                pq.push({nextVal, curr.row, curr.col + 1});
            } else {
                break; // One list exhausted
            }
        }

        return {rangeStart, rangeEnd};
    }
};
