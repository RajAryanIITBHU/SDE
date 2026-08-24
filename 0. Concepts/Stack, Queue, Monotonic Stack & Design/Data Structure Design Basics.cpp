/*
 * ============================================================================
 * Concept: Data Structure Design Basics (Min Stack & Circular Queue)
 * Subtopic: Stack, Queue, Monotonic Stack & Design
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Implements fundamental data structures with specific time bounds:
1. Min Stack (LC 155): Maintain secondary stack storing minimum values.
2. Queue using Stacks (LC 232): Amortized O(1) using input stack and output stack.
3. Circular Queue (LC 622): Fixed array with `head` and `tail` modulo arithmetic `(tail + 1) % capacity`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(1) amortized for push/pop/peek operations.
 * - Space Complexity: O(N) space storage.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Min Stack (LC 155).
- Implement Queue using Stacks (LC 232).
- Design Circular Queue (LC 622).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Min Stack implementation.
 */

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) minSt.push(val);
    }
    
    void pop() {
        if (st.top() == minSt.top()) minSt.pop();
        st.pop();
    }
    
    int top() { return st.top(); }
    int getMin() { return minSt.top(); }
};

int main() {
    MinStack ms;
    ms.push(-2); ms.push(0); ms.push(-3);
    cout << "Min: " << ms.getMin() << "\n"; // -3
    ms.pop();
    cout << "Top: " << ms.top() << "\n";   // 0
    cout << "Min: " << ms.getMin() << "\n"; // -2
    return 0;
}
