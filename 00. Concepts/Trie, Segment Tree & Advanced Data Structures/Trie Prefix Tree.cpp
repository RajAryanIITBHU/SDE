/*
 * ============================================================================
 * Concept: Trie (Prefix Tree) Core Implementation
 * Subtopic: Trie, Segment Tree & Advanced Data Structures
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Tree data structure used for efficient storage and retrieval of strings.
Each TrieNode contains an array/map of child pointers `children[26]` and a boolean `isEndOfWord` flag.
Allows $O(L)$ insertion, search, and prefix matching where $L$ is word length.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(L) per operation where L is string length.
 * - Space Complexity: O(ALPHABET_SIZE * N * L) space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Implement Trie (LC 208).
- Prefix matching or dictionary autocomplete.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Implement Trie (Prefix Tree) (LC 208).
2. Design Add and Search Words Data Structure (LC 211 - DFS with `.` wildcard).
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node->children[idx] = node->children[idx];
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << "Search apple: " << (trie.search("apple") ? "Yes" : "No") << "\n";
    cout << "Starts with app: " << (trie.startsWith("app") ? "Yes" : "No") << "\n";
    return 0;
}
