// Link: https://leetcode.com/problems/longest-repeating-character-replacement/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sliding Window + Max Frequency)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) (fixed 26-size array)
/*
PSEUDOCODE:
1. Create frequency array count of size 26.
2. Initialize left = 0, maxFreq = 0, ans = 0.
3. For right from 0 to n-1:
     count[s[right] - 'A']++
     maxFreq = max(maxFreq, count[s[right] - 'A'])
     // Invalid window: letters to replace > k
     While (right - left + 1) - maxFreq > k:
         count[s[left] - 'A']--
         left++
     ans = max(ans, right - left + 1)
4. Return ans.
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> count(26, 0);

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            // If characters needing replacement exceed k, shrink window
            while ((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
