// Link: https://leetcode.com/problems/shortest-encoding-of-words/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Suffix Elimination via Hash Set)
// ==========================================
// Time Complexity  : O(N * L^2)
// Space Complexity : O(N * L)
/*
PSEUDOCODE:
1. Store all words in unordered_set wordSet.
2. For each word in words:
     For i from 1 to word.length() - 1:
         wordSet.erase(word.substr(i)) // Remove any word that is a proper suffix of another
3. Total encoded length = sum of (word.length() + 1) for all remaining words in wordSet.
4. Return totalLength.
*/

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());

        // Remove any word that appears as a proper suffix of another word
        for (const string& word : words) {
            for (int i = 1; i < (int)word.length(); i++) {
                wordSet.erase(word.substr(i));
            }
        }

        int totalLen = 0;
        for (const string& word : wordSet) {
            totalLen += word.length() + 1; // +1 for the '#' delimiter
        }

        return totalLen;
    }
};
