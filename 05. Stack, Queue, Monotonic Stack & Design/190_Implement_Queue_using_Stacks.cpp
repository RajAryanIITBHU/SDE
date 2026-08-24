// Link: https://leetcode.com/problems/implement-queue-using-stacks/

#include <iostream>
#include <stack>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Two Stacks: inStack and outStack)
// ==========================================
// Time Complexity  : push: O(1), pop/peek: Amortized O(1)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain stack<int> inSt and stack<int> outSt.
2. push(x): inSt.push(x).
3. Helper shiftStacks():
     if outSt.empty():
         While !inSt.empty():
             outSt.push(inSt.top())
             inSt.pop()
4. pop(): shiftStacks(), val = outSt.top(), outSt.pop(), return val.
5. peek(): shiftStacks(), return outSt.top().
6. empty(): return inSt.empty() && outSt.empty().
*/

class MyQueue {
private:
    stack<int> inSt;
    stack<int> outSt;

    void shiftStacks() {
        if (outSt.empty()) {
            while (!inSt.empty()) {
                outSt.push(inSt.top());
                inSt.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inSt.push(x);
    }

    int pop() {
        shiftStacks();
        int val = outSt.top();
        outSt.pop();
        return val;
    }

    int peek() {
        shiftStacks();
        return outSt.top();
    }

    bool empty() {
        return inSt.empty() && outSt.empty();
    }
};
