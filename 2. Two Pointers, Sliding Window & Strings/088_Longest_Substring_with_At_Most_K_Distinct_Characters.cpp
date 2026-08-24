// Link: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sliding Window + Hash Map)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(k)
/*
PSEUDOCODE:
1. If k == 0 return 0.
2. Create hash map mp: char -> count.
3. Initialize left = 0, ans = 0.
4. For right from 0 to n-1:
     mp[s[right]]++
     While mp.size() > k:
         mp[s[left]]--
         if mp[s[left]] == 0 -> mp.erase(s[left])
         left++
     ans = max(ans, right - left + 1)
5. Return ans.
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;

        int n = s.length();
        unordered_map<char, int> mp;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            mp[s[right]]++;

            // Shrink window if more than k distinct characters
            while (mp.size() > k) {
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
