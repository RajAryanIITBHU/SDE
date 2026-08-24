// Link: https://leetcode.com/problems/word-search-ii/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Trie Node structure
struct TrieNode {
    TrieNode* children[26];
    string word; // Non-empty if this node is the end of a word

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        word = "";
    }
};

// ==========================================
// 1. OPTIMAL APPROACH (Prefix Tree + Grid DFS Backtracking)
// ==========================================
// Time Complexity  : O(n * m * 4^L), where L is max word length
// Space Complexity : O(total_words_characters)
/*
PSEUDOCODE:
1. Build Trie from words list.
2. Helper dfs(r, c, node, ans, board):
     if r < 0 || r >= n || c < 0 || c >= m || board[r][c] == '#' return
     cChar = board[r][c]
     childNode = node->children[cChar - 'a']
     if childNode == nullptr return
     if !childNode->word.empty():
         ans.push_back(childNode->word)
         childNode->word = "" // De-duplicate
     board[r][c] = '#' // Mark visited
     For each (dr, dc) in dirs:
         dfs(r + dr, c + dc, childNode, ans, board)
     board[r][c] = cChar // Backtrack
3. Run DFS from all cells in board starting from Trie root.
4. Return ans.
*/

class Solution {
private:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void insertWord(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = word;
    }

    void dfs(int r, int c, TrieNode* node, vector<string>& ans, vector<vector<char>>& board, int n, int m) {
        if (r < 0 || r >= n || c < 0 || c >= m || board[r][c] == '#') {
            return;
        }

        char orig = board[r][c];
        int idx = orig - 'a';

        if (node->children[idx] == nullptr) {
            return;
        }

        TrieNode* nextNode = node->children[idx];

        if (!nextNode->word.empty()) {
            ans.push_back(nextNode->word);
            nextNode->word = ""; // Prevent duplicate entries in answer
        }

        board[r][c] = '#'; // Mark visited

        for (auto& dir : dirs) {
            dfs(r + dir.first, c + dir.second, nextNode, ans, board, n, m);
        }

        board[r][c] = orig; // Backtrack
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) {
            insertWord(root, w);
        }

        int n = board.size();
        int m = board[0].size();
        vector<string> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(i, j, root, ans, board, n, m);
            }
        }

        return ans;
    }
};
