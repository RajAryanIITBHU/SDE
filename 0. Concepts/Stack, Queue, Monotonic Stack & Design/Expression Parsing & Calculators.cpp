/*
 * ============================================================================
 * Concept: Expression Parsing & RPN Calculators
 * Subtopic: Stack, Queue, Monotonic Stack & Design
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Parses algebraic expressions (infix notation) or Reverse Polish Notation (postfix notation) using stacks.
Handles operators `+`, `-`, `*`, `/`, parentheses `()`, and operator precedence.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time complexity.
 * - Space Complexity: O(N) space complexity.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Evaluate Reverse Polish Notation (LC 150).
- Basic Calculator I, II, III (LC 224, 227, 772).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. RPN Evaluation (LC 150).
2. Calculator with `+`, `-`, `*`, `/` (LC 227).
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// Evaluate RPN (LC 150)
int evalRPN(const vector<string>& tokens) {
    stack<int> st;
    for (const string& t : tokens) {
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (t == "+") st.push(a + b);
            else if (t == "-") st.push(a - b);
            else if (t == "*") st.push(a * b);
            else if (t == "/") st.push(a / b);
        } else {
            st.push(stoi(t));
        }
    }
    return st.top();
}

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << "RPN Result: " << evalRPN(tokens) << "\n";
    return 0;
}
