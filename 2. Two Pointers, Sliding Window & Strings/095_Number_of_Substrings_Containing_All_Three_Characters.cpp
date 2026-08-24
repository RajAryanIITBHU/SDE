// Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Last Seen Positions)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize lastSeen = {-1, -1, -1}, ans = 0.
2. For i from 0 to n-1:
     lastSeen[s[i] - 'a'] = i
     // If all 3 characters have been seen, any substring starting from 0 up to min(lastSeen) is valid
     if lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1:
         ans += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]})
3. Return ans.
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> lastSeen = {-1, -1, -1}; // Indices of 'a', 'b', 'c'
        int ans = 0;

        for (int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;

            // Every start index <= min(lastSeen) forms a valid substring ending at i
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                ans += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }

        return ans;
    }
};
