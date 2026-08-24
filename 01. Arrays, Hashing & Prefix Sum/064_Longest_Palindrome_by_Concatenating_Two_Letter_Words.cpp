// Link: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (2D Frequency Array)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) (fixed 26x26 matrix)
/*
PSEUDOCODE:
1. Create 26x26 frequency array count.
2. ans = 0.
3. For each word in words:
     a = word[0] - 'a', b = word[1] - 'a'
     if count[b][a] > 0: // Reversed word is available
         count[b][a]--
         ans += 4 // (each 2-letter word is length 2, so pair is length 4)
     else:
         count[a][b]++
4. Check if any symmetric word (e.g. "aa", "bb") is left over to place at the center:
     For i from 0 to 25:
         if count[i][i] > 0:
             ans += 2
             break
5. Return ans.
*/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> count(26, vector<int>(26, 0));
        int ans = 0;

        for (string& word : words) {
            int a = word[0] - 'a';
            int b = word[1] - 'a';

            // If reverse word (b, a) exists, pair them up
            if (count[b][a] > 0) {
                ans += 4;
                count[b][a]--;
            } else {
                count[a][b]++;
            }
        }

        // Place one remaining symmetric pair in the middle if available
        for (int i = 0; i < 26; i++) {
            if (count[i][i] > 0) {
                ans += 2;
                break;
            }
        }

        return ans;
    }
};
