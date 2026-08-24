// Link: https://leetcode.com/problems/validate-stack-sequences/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Stack Simulation)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize stack<int> st, popIdx = 0.
2. For each x in pushed:
     st.push(x)
     While !st.empty() && popIdx < popped.size() && st.top() == popped[popIdx]:
         st.pop()
         popIdx++
3. Return st.empty().
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int popIdx = 0;

        for (int x : pushed) {
            st.push(x);

            // Greedily pop matching elements
            while (!st.empty() && popIdx < (int)popped.size() && st.top() == popped[popIdx]) {
                st.pop();
                popIdx++;
            }
        }

        return st.empty();
    }
};
