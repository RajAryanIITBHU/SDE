// Link: https://leetcode.com/problems/longest-word-in-dictionary/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sorting + Hash Set Prefix Verification)
// ==========================================
// Time Complexity  : O(N log N + N * L)
// Space Complexity : O(N * L)
/*
PSEUDOCODE:
1. Sort words:
     - By length in ascending order
     - If lengths are equal, by lexicographical order in descending order
2. Maintain builtWords set initialized with {""}.
3. longestWord = "".
4. For each word in words:
     if builtWords.count(word.substr(0, word.length() - 1)):
         builtWords.insert(word)
         longestWord = word // Automatically picks longer or lexicographically smaller word
5. Return longestWord.
*/

class Solution {
public:
    string longestWord(vector<string>& words) {
        // Sort by length asc; for ties, sort lexicographically desc
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            if (a.length() == b.length()) return a > b;
            return a.length() < b.length();
        });

        unordered_set<string> builtWords;
        builtWords.insert("");
        string longest = "";

        for (const string& word : words) {
            // Check if prefix of length L - 1 exists in builtWords
            if (builtWords.find(word.substr(0, word.length() - 1)) != builtWords.end()) {
                builtWords.insert(word);
                longest = word;
            }
        }

        return longest;
    }
};
