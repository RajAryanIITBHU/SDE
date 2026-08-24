// Link: https://leetcode.com/problems/prefix-and-suffix-search/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Trie with Wrapped Suffix-Delimiter-Word Strings)
// ==========================================
// Time Complexity  : Constructor: O(N * L^2), f: O(pref_len + suff_len)
// Space Complexity : O(N * L^2)
/*
PSEUDOCODE:
To query prefix and suffix simultaneously:
Insert all variations: suffix + '{' + word into a single Trie, storing maxIndex at each node.
1. For each word with index i:
     For j from 0 to word.length():
         wrapped = word.substr(j) + '{' + word
         insert wrapped with weight i into Trie.
2. f(pref, suff):
     search for suff + '{' + pref in Trie.
     Return maxIndex on terminal node (or -1 if not found).
*/

class WordFilter {
private:
    struct TrieNode {
        TrieNode* children[27]; // 26 letters + '{' (ASCII 123, right after 'z')
        int maxIndex;

        TrieNode() {
            for (int i = 0; i < 27; i++) children[i] = nullptr;
            maxIndex = -1;
        }
    };

    TrieNode* root;

    void insert(const string& str, int weight) {
        TrieNode* curr = root;
        for (char c : str) {
            int idx = c - 'a'; // '{' - 'a' maps to 26
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
            curr->maxIndex = weight;
        }
    }

public:
    WordFilter(vector<string>& words) {
        root = new TrieNode();

        for (int i = 0; i < (int)words.size(); i++) {
            string word = words[i];
            int len = word.length();

            // Insert all combinations: suffix + '{' + word
            for (int j = 0; j <= len; j++) {
                string wrapped = word.substr(j) + '{' + word;
                insert(wrapped, i);
            }
        }
    }

    int f(string pref, string suff) {
        string query = suff + '{' + pref;
        TrieNode* curr = root;

        for (char c : query) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return -1;
            }
            curr = curr->children[idx];
        }

        return curr->maxIndex;
    }
};
