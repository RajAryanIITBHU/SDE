// Link: https://leetcode.com/problems/group-anagrams/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BETTER APPROACH (Sorting String as Map Key)
// ==========================================
// Time Complexity  : O(n * k log k), where n = number of strings, k = max string length
// Space Complexity : O(n * k)
/*
PSEUDOCODE:
1. Create hash map mp: string -> vector<string>.
2. For each string s in strs:
     key = s
     sort key alphabetically
     mp[key].push_back(s)
3. Collect all values from mp into ans.
4. Return ans.
*/

class SolutionBetter {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Frequency Count String as Key)
// ==========================================
// Time Complexity  : O(n * k)
// Space Complexity : O(n * k)
/*
PSEUDOCODE:
1. Create hash map mp: string -> vector<string>.
2. For each string s in strs:
     Count frequencies of 26 characters in count array.
     Build unique key string (e.g., "1#0#2#...").
     mp[key].push_back(s)
3. Collect all values from mp into ans.
4. Return ans.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }

            // Build key from character counts
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + "#";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
