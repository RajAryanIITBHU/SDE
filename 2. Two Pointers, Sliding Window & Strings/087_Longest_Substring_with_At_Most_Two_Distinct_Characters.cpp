// Link: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sliding Window + Hash Map)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) (map has at most 3 characters)
/*
PSEUDOCODE:
1. Create hash map mp: char -> count.
2. Initialize left = 0, ans = 0.
3. For right from 0 to n-1:
     mp[s[right]]++
     While mp.size() > 2:
         mp[s[left]]--
         if mp[s[left]] == 0 -> mp.erase(s[left])
         left++
     ans = max(ans, right - left + 1)
4. Return ans.
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        unordered_map<char, int> mp;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            mp[s[right]]++;

            // Shrink window if more than 2 distinct characters
            while (mp.size() > 2) {
                mp[s[left]]--;
                if (mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
