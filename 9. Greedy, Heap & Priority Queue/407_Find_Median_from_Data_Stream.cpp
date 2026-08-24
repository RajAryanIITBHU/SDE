// Link: https://leetcode.com/problems/find-median-from-data-stream/

#include <iostream>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Two Heaps: Max-Heap Left & Min-Heap Right)
// ==========================================
// Time Complexity  : addNum: O(log n), findMedian: O(1)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Max-heap leftHalf stores smaller half of elements.
2. Min-heap rightHalf stores larger half of elements.
3. addNum(num):
     leftHalf.push(num)
     rightHalf.push(leftHalf.top()), leftHalf.pop()
     if leftHalf.size() < rightHalf.size():
         leftHalf.push(rightHalf.top()), rightHalf.pop()
4. findMedian():
     if leftHalf.size() > rightHalf.size() return leftHalf.top()
     return (leftHalf.top() + rightHalf.top()) / 2.0
*/

class MedianFinder {
private:
    priority_queue<int> leftHalf;                             // Max-heap
    priority_queue<int, vector<int>, greater<int>> rightHalf; // Min-heap

public:
    MedianFinder() {}

    void addNum(int num) {
        leftHalf.push(num);

        // Maintain leftHalf <= rightHalf
        rightHalf.push(leftHalf.top());
        leftHalf.pop();

        // Maintain leftHalf size >= rightHalf size
        if (leftHalf.size() < rightHalf.size()) {
            leftHalf.push(rightHalf.top());
            rightHalf.pop();
        }
    }

    double findMedian() {
        if (leftHalf.size() > rightHalf.size()) {
            return leftHalf.top();
        }
        return (leftHalf.top() + rightHalf.top()) / 2.0;
    }
};
