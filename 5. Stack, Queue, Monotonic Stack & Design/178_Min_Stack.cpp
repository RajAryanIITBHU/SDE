// Link: https://leetcode.com/problems/min-stack/

#include <iostream>
#include <stack>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Stack of Pairs)
// ==========================================
// Time Complexity  : O(1) for all operations
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain stack<pair<int, int>> st storing {value, currentMin}.
2. push(val):
     minVal = st.empty() ? val : min(val, st.top().second)
     st.push({val, minVal})
3. pop(): st.pop()
4. top(): return st.top().first
5. getMin(): return st.top().second
*/

class MinStack {
private:
    stack<pair<int, int>> st; // {val, currentMin}

public:
    MinStack() {}

    void push(int val) {
        int currentMin = st.empty() ? val : min(val, st.top().second);
        st.push({val, currentMin});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};
