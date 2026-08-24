// Link: https://leetcode.com/problems/number-of-matching-subsequences/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BETTER APPROACH (Binary Search on Character Positions)
// ==========================================
// Time Complexity  : O(total_chars_in_words * log(s.length()))
// Space Complexity : O(s.length())
/*
PSEUDOCODE:
1. Store indices of each character in s: pos[26].
2. For each word in words:
     currIdx = -1, isSubseq = true
     For each char c in word:
         Find smallest index in pos[c - 'a'] > currIdx using upper_bound.
         if not found -> isSubseq = false, break
         currIdx = found_index
     if isSubseq -> ans++
3. Return ans.
*/

class SolutionBetter {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.length(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }

        int ans = 0;

        for (string& word : words) {
            int currIdx = -1;
            bool isSubseq = true;

            for (char c : word) {
                auto& list = pos[c - 'a'];
                auto it = upper_bound(list.begin(), list.end(), currIdx);

                if (it == list.end()) {
                    isSubseq = false;
                    break;
                }
                currIdx = *it;
            }

            if (isSubseq) ans++;
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Bucket of Waiting Word Pointers)
// ==========================================
// Time Complexity  : O(s.length() + sum(word.length()))
// Space Complexity : O(words.size())
/*
PSEUDOCODE:
1. Create 26 buckets: waiting[26] where waiting[c] stores pairs {word_index, char_index}.
2. Initially, for each word, add {i, 0} to waiting[words[i][0] - 'a'].
3. Traverse each char c in s:
     Take all entries in waiting[c - 'a']. Clear bucket.
     For each {wordIdx, charIdx}:
         charIdx++
         if charIdx == words[wordIdx].length() -> ans++
         else -> waiting[words[wordIdx][charIdx] - 'a'].push_back({wordIdx, charIdx})
4. Return ans.
*/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // waiting[c] stores pairs of {wordIndex, nextCharIndexToMatch}
        vector<vector<pair<int, int>>> waiting(26);

        for (int i = 0; i < words.size(); i++) {
            waiting[words[i][0] - 'a'].push_back({i, 0});
        }

        int ans = 0;

        for (char c : s) {
            auto currentBucket = waiting[c - 'a'];
            waiting[c - 'a'].clear();

            for (auto& it : currentBucket) {
                int wordIdx = it.first;
                int charIdx = it.second + 1;

                // Word fully matched
                if (charIdx == words[wordIdx].length()) {
                    ans++;
                } else {
                    waiting[words[wordIdx][charIdx] - 'a'].push_back({wordIdx, charIdx});
                }
            }
        }

        return ans;
    }
};
