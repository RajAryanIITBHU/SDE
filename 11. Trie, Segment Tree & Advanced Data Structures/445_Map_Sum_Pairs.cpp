// Link: https://leetcode.com/problems/map-sum-pairs/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Prefix Trie with Cumulative Sums)
// ==========================================
// Time Complexity  : insert: O(L), sum: O(L), where L is word length
// Space Complexity : O(total_inserted_chars)
/*
PSEUDOCODE:
1. TrieNode with children[26] and score.
2. Maintain map<string, int> wordValues.
3. insert(key, val):
     delta = val - wordValues[key]
     wordValues[key] = val
     For c in key:
         curr = curr->children[c - 'a']
         curr->score += delta
4. sum(prefix):
     For c in prefix:
         if child is null return 0
         curr = curr->children[c - 'a']
     return curr->score
*/

class MapSum {
private:
    struct TrieNode {
        TrieNode* children[26];
        int score;

        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
            score = 0;
        }
    };

    TrieNode* root;
    unordered_map<string, int> wordValues;

public:
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        int delta = val - wordValues[key];
        wordValues[key] = val;

        TrieNode* curr = root;
        for (char c : key) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
            curr->score += delta;
        }
    }

    int sum(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return 0;
            }
            curr = curr->children[idx];
        }
        return curr->score;
    }
};
