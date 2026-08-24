// Link: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Bitmask Backtracking DFS)
// ==========================================
// Time Complexity  : O(2^n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Helper getMask(s): returns 26-bit mask if all chars unique, or -1 if duplicate inside s.
2. Filter arr: store only valid strings with their masks and lengths.
3. Helper backtrack(idx, currentMask, currentLen, maxLen):
     maxLen = max(maxLen, currentLen)
     For i from idx to validList.size() - 1:
         if (currentMask & validList[i].mask) == 0:
             backtrack(i + 1, currentMask | validList[i].mask, currentLen + validList[i].len, maxLen)
4. Return maxLen.
*/

class Solution {
private:
    struct StringInfo {
        int mask;
        int len;
    };

    int getMask(const string& s) {
        int mask = 0;
        for (char c : s) {
            int bit = 1 << (c - 'a');
            if (mask & bit) return -1; // Duplicate within the string
            mask |= bit;
        }
        return mask;
    }

    void backtrack(int idx, int currentMask, int currentLen, int& maxLen, const vector<StringInfo>& validList) {
        maxLen = max(maxLen, currentLen);

        for (int i = idx; i < (int)validList.size(); i++) {
            if ((currentMask & validList[i].mask) == 0) {
                backtrack(i + 1, currentMask | validList[i].mask, currentLen + validList[i].len, maxLen, validList);
            }
        }
    }

public:
    int maxLength(vector<string>& arr) {
        vector<StringInfo> validList;

        for (const string& s : arr) {
            int mask = getMask(s);
            if (mask != -1) {
                validList.push_back({mask, (int)s.length()});
            }
        }

        int maxLen = 0;
        backtrack(0, 0, 0, maxLen, validList);
        return maxLen;
    }
};
