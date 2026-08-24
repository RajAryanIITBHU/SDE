// Link: https://leetcode.com/problems/partition-labels/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Last-Index Interval Expansion)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) (26 characters)
/*
PSEUDOCODE:
1. Store last occurrence index of every character in lastIndex array.
2. start = 0, currentEnd = 0, vector<int> ans.
3. For i from 0 to n-1:
     currentEnd = max(currentEnd, lastIndex[s[i] - 'a'])
     if i == currentEnd:
         ans.push_back(i - start + 1)
         start = i + 1
4. Return ans.
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26, 0);
        int n = s.length();

        for (int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int start = 0;
        int currentEnd = 0;

        for (int i = 0; i < n; i++) {
            currentEnd = max(currentEnd, lastIndex[s[i] - 'a']);

            // When reaching the farthest last occurrence in current partition
            if (i == currentEnd) {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};
