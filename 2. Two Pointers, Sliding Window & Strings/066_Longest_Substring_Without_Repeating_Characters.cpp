// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Check All Substrings)
// ==========================================
// Time Complexity  : O(n^3)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize ans = 0.
2. For i from 0 to n-1:
     For j from i to n-1:
         Check if all characters in s[i..j] are unique using a set.
         if unique -> ans = max(ans, j - i + 1)
3. Return ans.
*/

class SolutionBruteForce {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            for (int j = i; j < n; j++) {
                if (st.count(s[j])) {
                    break;
                }
                st.insert(s[j]);
                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};

// ==========================================
// 2. BETTER APPROACH (Sliding Window + Hash Set)
// ==========================================
// Time Complexity  : O(2n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize unordered_set st, left = 0, ans = 0.
2. For right from 0 to n-1:
     While st contains s[right]:
         st.erase(s[left])
         left++
     st.insert(s[right])
     ans = max(ans, right - left + 1)
3. Return ans.
*/

class SolutionBetter {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> st;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            while (st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Sliding Window + Last Seen Index Array)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) (fixed 256-size ASCII array)
/*
PSEUDOCODE:
1. Create lastSeen array of size 256 filled with -1.
2. Initialize left = 0, ans = 0.
3. For right from 0 to n-1:
     char c = s[right]
     if lastSeen[c] >= left:
         left = lastSeen[c] + 1 // Jump left pointer directly past duplicate
     lastSeen[c] = right
     ans = max(ans, right - left + 1)
4. Return ans.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> lastSeen(256, -1);
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            char c = s[right];

            // If character seen within current window, jump left pointer
            if (lastSeen[c] >= left) {
                left = lastSeen[c] + 1;
            }

            lastSeen[c] = right;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
