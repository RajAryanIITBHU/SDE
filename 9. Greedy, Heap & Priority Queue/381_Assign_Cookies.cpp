// Link: https://leetcode.com/problems/assign-cookies/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Two Pointers on Sorted Arrays)
// ==========================================
// Time Complexity  : O(n log n + m log m)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Sort g (children greed factor) and s (cookie sizes) in ascending order.
2. childIdx = 0, cookieIdx = 0.
3. While childIdx < g.size() && cookieIdx < s.size():
     if s[cookieIdx] >= g[childIdx]:
         childIdx++
     cookieIdx++
4. Return childIdx.
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int childIdx = 0;
        int cookieIdx = 0;

        while (childIdx < (int)g.size() && cookieIdx < (int)s.size()) {
            if (s[cookieIdx] >= g[childIdx]) {
                childIdx++; // Satisfy current child
            }
            cookieIdx++;    // Move to next cookie
        }

        return childIdx;
    }
};
