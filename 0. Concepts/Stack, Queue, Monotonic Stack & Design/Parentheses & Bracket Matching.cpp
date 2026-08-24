/*
 * ============================================================================
 * Concept: Parentheses & Bracket Matching
 * Subtopic: Stack, Queue, Monotonic Stack & Design
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Uses a LIFO Stack to match opening brackets with corresponding closing brackets in correct sequence.
Push opening brackets `(`, `{`, `[` onto stack; when encountering closing brackets `)`, `}`, `]`, check if stack top matches.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time complexity.
 * - Space Complexity: O(N) space for stack.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Valid Parentheses (LC 20).
- Minimum Add / Remove to Make Parentheses Valid.
- Decode String (LC 394 - Stacks for numbers and strings).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Valid Parentheses (LC 20).
2. Decode String (LC 394).
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') st.push(c);
        else {
            if (st.empty()) return false;
            if (c == ')' && st.top() != '(') return false;
            if (c == '}' && st.top() != '{') return false;
            if (c == ']' && st.top() != '[') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s = "()[]{}";
    cout << "Is Valid: " << (isValid(s) ? "Yes" : "No") << "\n";
    return 0;
}
