// Link: https://leetcode.com/problems/valid-anagram/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Sorting)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(1) or O(n)
/*
PSEUDOCODE:
1. If lengths of s and t are not equal, return false.
2. Sort string s: sort(s.begin(), s.end()).
3. Sort string t: sort(t.begin(), t.end()).
4. Return s == t.
*/

class SolutionBruteForce {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Fixed Frequency Array)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) (fixed 26-size array)
/*
PSEUDOCODE:
1. If lengths of s and t are not equal, return false.
2. Create frequency array arr of size 26 initialized to 0.
3. For each index i from 0 to n-1:
     arr[s[i] - 'a']++
     arr[t[i] - 'a']--
4. Check if all elements in arr are 0:
     If any arr[i] != 0 -> return false.
5. Return true.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int n = s.length();
        vector<int> arr(26, 0);

        for (int i = 0; i < n; i++) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
