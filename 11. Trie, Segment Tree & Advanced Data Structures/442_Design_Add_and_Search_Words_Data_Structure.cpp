// Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/

#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Trie with Wildcard '.' DFS Search)
// ==========================================
// Time Complexity  : addWord: O(L), search: O(26^D) worst case where D is wildcard count
// Space Complexity : O(total_words_length)
/*
PSEUDOCODE:
1. TrieNode with children[26] and isEnd.
2. addWord(word): standard Trie insertion.
3. searchDFS(word, idx, node):
     if node == nullptr return false
     if idx == word.length() return node->isEnd
     if word[idx] == '.':
         For i from 0 to 25:
             if node->children[i] != nullptr && searchDFS(word, idx + 1, node->children[i]) return true
         return false
     else:
         return searchDFS(word, idx + 1, node->children[word[idx] - 'a'])
*/

class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
            isEnd = false;
        }
    };

    TrieNode* root;

    bool searchDFS(const string& word, int idx, TrieNode* node) {
        if (node == nullptr) return false;
        if (idx == (int)word.length()) return node->isEnd;

        if (word[idx] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr && searchDFS(word, idx + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            return searchDFS(word, idx + 1, node->children[word[idx] - 'a']);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
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

    bool search(string word) {
        return searchDFS(word, 0, root);
    }
};
