// Link: https://leetcode.com/problems/implement-trie-prefix-tree/

#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Prefix Tree / Trie Node Array)
// ==========================================
// Time Complexity  : insert, search, startsWith: O(L), where L is word length
// Space Complexity : O(total_inserted_characters)
/*
PSEUDOCODE:
1. TrieNode structure with children[26] and isEnd boolean flag.
2. insert(word):
     traverse node by node, allocate new TrieNode if child is null, set isEnd = true on final node.
3. search(word):
     traverse node by node, if any child is null return false, return curr->isEnd.
4. startsWith(prefix):
     traverse node by node, if any child is null return false, return true.
*/

class Trie {
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

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
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
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};
