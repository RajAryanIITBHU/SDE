// Link: https://leetcode.com/problems/encode-and-decode-strings/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Length-Prefix Encoding: len#string)
// ==========================================
// Time Complexity  : O(N) for both encode and decode, where N is total characters
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
Encode:
1. Initialize encoded = "".
2. For each string s in strs:
     encoded += to_string(s.length()) + "#" + s
3. Return encoded.

Decode:
1. Initialize ans vector, i = 0.
2. While i < s.length():
     Find position of delimiter '#' starting from i: pos = s.find('#', i)
     len = stoi(s.substr(i, pos - i))
     str = s.substr(pos + 1, len)
     ans.push_back(str)
     i = pos + 1 + len
3. Return ans.
*/

class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";

        for (string& s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }

        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        int n = s.length();

        while (i < n) {
            // Find delimiter '#'
            int pos = s.find('#', i);
            int len = stoi(s.substr(i, pos - i));

            // Extract original string using parsed length
            string word = s.substr(pos + 1, len);
            ans.push_back(word);

            // Move pointer to the start of the next encoded string
            i = pos + 1 + len;
        }

        return ans;
    }
};
