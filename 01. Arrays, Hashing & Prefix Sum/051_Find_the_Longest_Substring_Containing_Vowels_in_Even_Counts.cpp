// Link: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Prefix XOR Bitmask)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) (state space is 2^5 = 32)
/*
PSEUDOCODE:
1. Map vowels to bit positions: 'a'->0, 'e'->1, 'i'->2, 'o'->3, 'u'->4.
2. Initialize seen array of size 32 with -2, seen[0] = -1.
3. mask = 0, ans = 0.
4. For i from 0 to n-1:
     if s[i] is vowel -> flip corresponding bit in mask: mask ^= (1 << bit)
     if seen[mask] != -2:
         ans = max(ans, i - seen[mask])
     else:
         seen[mask] = i
5. Return ans.
*/

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        // Stores first occurrence index of each bitmask (0 to 31)
        vector<int> seen(32, -2);
        seen[0] = -1; // Base case: initial mask 0 occurs before index 0

        int mask = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') mask ^= (1 << 0);
            else if (s[i] == 'e') mask ^= (1 << 1);
            else if (s[i] == 'i') mask ^= (1 << 2);
            else if (s[i] == 'o') mask ^= (1 << 3);
            else if (s[i] == 'u') mask ^= (1 << 4);

            if (seen[mask] != -2) {
                ans = max(ans, i - seen[mask]);
            } else {
                seen[mask] = i;
            }
        }

        return ans;
    }
};
