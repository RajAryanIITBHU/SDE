// Link: https://leetcode.com/problems/implement-stack-using-queues/

#include <iostream>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Single Queue Rotation)
// ==========================================
// Time Complexity  : push: O(n), pop/top/empty: O(1)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain single queue<int> q.
2. push(x):
     q.push(x)
     Rotate previous elements:
         For i from 0 to q.size() - 2:
             q.push(q.front())
             q.pop()
3. pop(): val = q.front(), q.pop(), return val.
4. top(): return q.front().
5. empty(): return q.empty().
*/

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        int sz = q.size();

        // Rotate existing elements behind the newly added element
        for (int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
