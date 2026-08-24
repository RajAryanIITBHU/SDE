// Link: https://leetcode.com/problems/design-circular-deque/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Array with Front and Rear Indices)
// ==========================================
// Time Complexity  : O(1) for all operations
// Space Complexity : O(k)
/*
PSEUDOCODE:
1. Maintain vector<int> arr of size k, front = 0, rear = 0, count = 0, cap = k.
2. insertFront(value):
     if isFull() return false
     front = (front - 1 + cap) % cap
     arr[front] = value
     count++
     return true
3. insertLast(value):
     if isFull() return false
     arr[rear] = value
     rear = (rear + 1) % cap
     count++
     return true
4. deleteFront():
     if isEmpty() return false
     front = (front + 1) % cap
     count--
     return true
5. deleteLast():
     if isEmpty() return false
     rear = (rear - 1 + cap) % cap
     count--
     return true
6. getFront(): return isEmpty() ? -1 : arr[front]
7. getRear(): return isEmpty() ? -1 : arr[(rear - 1 + cap) % cap]
8. isEmpty(): return count == 0
9. isFull(): return count == cap
*/

class MyCircularDeque {
private:
    vector<int> arr;
    int front;
    int rear;
    int count;
    int cap;

public:
    MyCircularDeque(int k) {
        arr.resize(k);
        front = 0;
        rear = 0;
        count = 0;
        cap = k;
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        front = (front - 1 + cap) % cap;
        arr[front] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        arr[rear] = value;
        rear = (rear + 1) % cap;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        front = (front + 1) % cap;
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        rear = (rear - 1 + cap) % cap;
        count--;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : arr[front];
    }

    int getRear() {
        return isEmpty() ? -1 : arr[(rear - 1 + cap) % cap];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == cap;
    }
};
