// Link: https://leetcode.com/problems/reverse-words-in-a-string/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BETTER APPROACH (StringStream Tokenization)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Use stringstream to extract words skipping whitespace.
2. Store words in vector words.
3. Reverse vector words and join with single spaces.
*/

class SolutionBetter {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i < (int)words.size() - 1) ans += " ";
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Two Pointers In-place Reversal)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) auxiliary space (modifying string in-place)
/*
PSEUDOCODE:
1. Clean spaces: shift words and compress multiple spaces to single spaces.
2. Reverse entire cleaned string.
3. Reverse each individual word within the string.
4. Return s.
*/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0, j = 0;

        // Step 1: Clean spaces in-place
        while (j < n) {
            while (j < n && s[j] == ' ') j++; // Skip leading/multiple spaces
            if (j < n && i > 0) s[i++] = ' '; // Add single space between words
            int start = i;
            while (j < n && s[j] != ' ') s[i++] = s[j++]; // Copy word
            reverse(s.begin() + start, s.begin() + i); // Reverse individual word
        }
        s.resize(i); // Resize string to valid characters

        // Step 2: Reverse entire string
        reverse(s.begin(), s.end());

        return s;
    }
};
