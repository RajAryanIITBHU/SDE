// Link: https://leetcode.com/problems/word-search/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Grid DFS Backtracking with In-Place Masking)
// ==========================================
// Time Complexity  : O(n * m * 3^L), where L is word length
// Space Complexity : O(L)
/*
PSEUDOCODE:
1. Helper dfs(r, c, wordIdx):
     if wordIdx == word.length() return true
     if r < 0 || r >= n || c < 0 || c >= m || board[r][c] != word[wordIdx] return false
     temp = board[r][c]
     board[r][c] = '#' // Mark visited
     For each (dr, dc) in dirs:
         if dfs(r + dr, c + dc, wordIdx + 1) return true
     board[r][c] = temp // Backtrack
     return false
2. For i from 0 to n-1:
     For j from 0 to m-1:
         if dfs(i, j, 0) return true
3. Return false.
*/

class Solution {
private:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int wordIdx, int n, int m) {
        if (wordIdx == (int)word.length()) {
            return true;
        }

        if (r < 0 || r >= n || c < 0 || c >= m || board[r][c] != word[wordIdx]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#'; // Mark visited

        for (auto& dir : dirs) {
            if (dfs(board, word, r + dir.first, c + dir.second, wordIdx + 1, n, m)) {
                board[r][c] = temp; // Restore before returning true
                return true;
            }
        }

        board[r][c] = temp; // Backtrack
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, word, i, j, 0, n, m)) {
                    return true;
                }
            }
        }

        return false;
    }
};
