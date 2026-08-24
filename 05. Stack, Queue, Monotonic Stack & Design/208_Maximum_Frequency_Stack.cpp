// Link: https://leetcode.com/problems/maximum-frequency-stack/

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Frequency Map + Grouped Stacks)
// ==========================================
// Time Complexity  : O(1) for push and pop
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain:
     freq: val -> count
     groupToStack: frequency -> stack of elements with at least that frequency
     maxFreq: maximum current frequency
2. push(val):
     f = ++freq[val]
     maxFreq = max(maxFreq, f)
     groupToStack[f].push(val)
3. pop():
     val = groupToStack[maxFreq].top()
     groupToStack[maxFreq].pop()
     freq[val]--
     if groupToStack[maxFreq].empty() -> maxFreq--
     return val
*/

class FreqStack {
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> groupToStack;
    int maxFreq;

public:
    FreqStack() {
        maxFreq = 0;
    }

    void push(int val) {
        int f = ++freq[val];
        maxFreq = max(maxFreq, f);
        groupToStack[f].push(val);
    }

    int pop() {
        int val = groupToStack[maxFreq].top();
        groupToStack[maxFreq].pop();

        freq[val]--;
        if (groupToStack[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};
