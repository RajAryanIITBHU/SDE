// Link: https://leetcode.com/problems/maximum-length-of-pair-chain/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Interval Scheduling)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Sort pairs by end time pairs[i][1] in ascending order.
2. currEnd = INT_MIN, chainLen = 0.
3. For each pair (start, end) in pairs:
     if start > currEnd:
         currEnd = end
         chainLen++
4. Return chainLen.
*/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort pairs by right endpoint (end time)
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int currEnd = INT_MIN;
        int chainLen = 0;

        for (const auto& pair : pairs) {
            if (pair[0] > currEnd) {
                currEnd = pair[1];
                chainLen++;
            }
        }

        return chainLen;
    }
};
