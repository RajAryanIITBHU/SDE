// Link: https://leetcode.com/problems/replace-words/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Prefix Trie for Shortest Root Replacement)
// ==========================================
// Time Complexity  : O(dictionary_chars + sentence_chars)
// Space Complexity : O(dictionary_chars)
/*
PSEUDOCODE:
1. Build Trie from dictionary roots.
2. Helper findShortestRoot(word, root):
     curr = root, prefix = ""
     For c in word:
         if curr->isEnd return prefix
         if curr->children[c - 'a'] == nullptr return word
         prefix += c
         curr = curr->children[c - 'a']
     return curr->isEnd ? prefix : word
3. Split sentence into words, replace each with findShortestRoot.
4. Join words with spaces and return.
*/

class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
            isEnd = false;
        }
    };

    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

    string findShortestRoot(const string& word, TrieNode* root) {
        TrieNode* curr = root;
        string prefix = "";

        for (char c : word) {
            if (curr->isEnd) {
                return prefix;
            }
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return word;
            }
            prefix += c;
            curr = curr->children[idx];
        }

        return curr->isEnd ? prefix : word;
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();
        for (const string& dictWord : dictionary) {
            insert(root, dictWord);
        }

        stringstream ss(sentence);
        string word;
        string ans = "";

        while (ss >> word) {
            if (!ans.empty()) ans += " ";
            ans += findShortestRoot(word, root);
        }

        return ans;
    }
};
