// Link: https://leetcode.com/problems/design-circular-queue/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Array with Head and Tail Pointers)
// ==========================================
// Time Complexity  : O(1) for all operations
// Space Complexity : O(k)
/*
PSEUDOCODE:
1. Maintain vector<int> arr of size k, head = 0, tail = -1, count = 0, cap = k.
2. enQueue(value):
     if isFull() return false
     tail = (tail + 1) % cap
     arr[tail] = value
     count++
     return true
3. deQueue():
     if isEmpty() return false
     head = (head + 1) % cap
     count--
     return true
4. Front(): return isEmpty() ? -1 : arr[head]
5. Rear(): return isEmpty() ? -1 : arr[tail]
6. isEmpty(): return count == 0
7. isFull(): return count == cap
*/

class MyCircularQueue {
private:
    vector<int> arr;
    int head;
    int tail;
    int count;
    int cap;

public:
    MyCircularQueue(int k) {
        arr.resize(k);
        head = 0;
        tail = -1;
        count = 0;
        cap = k;
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        tail = (tail + 1) % cap;
        arr[tail] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        head = (head + 1) % cap;
        count--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : arr[head];
    }

    int Rear() {
        return isEmpty() ? -1 : arr[tail];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == cap;
    }
};
