// Link: https://leetcode.com/problems/word-ladder/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (BFS Shortest Word Transformation Path)
// ==========================================
// Time Complexity  : O(N * L * 26), where N is wordList size, L is word length
// Space Complexity : O(N * L)
/*
PSEUDOCODE:
1. Store wordList in unordered_set wordSet.
2. If endWord not in wordSet return 0.
3. Initialize queue<string> q, push beginWord, level = 1.
4. While !q.empty():
     levelSize = q.size()
     For i from 0 to levelSize - 1:
         word = q.front(), q.pop()
         if word == endWord return level
         For j from 0 to word.length() - 1:
             origChar = word[j]
             For c from 'a' to 'z':
                 word[j] = c
                 if wordSet.count(word):
                     wordSet.erase(word) // Mark visited
                     q.push(word)
             word[j] = origChar // Restore
     level++
5. Return 0.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        int level = 1;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                string word = q.front();
                q.pop();

                if (word == endWord) {
                    return level;
                }

                // Try changing each character from 'a' to 'z'
                for (int j = 0; j < (int)word.length(); j++) {
                    char orig = word[j];

                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;

                        if (wordSet.find(word) != wordSet.end()) {
                            wordSet.erase(word); // Remove to mark as visited
                            q.push(word);
                        }
                    }

                    word[j] = orig; // Reset character
                }
            }

            level++;
        }

        return 0;
    }
};
