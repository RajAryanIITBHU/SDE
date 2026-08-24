// Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Word-Aligned Sliding Window)
// ==========================================
// Time Complexity  : O(wordLen * (s.length() / wordLen)) = O(s.length())
// Space Complexity : O(words.size() * wordLen)
/*
PSEUDOCODE:
1. wordLen = words[0].length(), numWords = words.size(), totalLen = wordLen * numWords.
2. Build wordCount map for words.
3. For offset from 0 to wordLen - 1:
     left = offset, count = 0, currentCount map.
     For right from offset to s.length() - wordLen by step wordLen:
         word = s.substr(right, wordLen)
         if word exists in wordCount:
             currentCount[word]++
             count++
             While currentCount[word] > wordCount[word]:
                 leftWord = s.substr(left, wordLen)
                 currentCount[leftWord]--
                 count--
                 left += wordLen
             if count == numWords:
                 ans.push_back(left)
         else:
             currentCount.clear()
             count = 0
             left = right + wordLen
4. Return ans.
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        int numWords = words.size();
        int wordLen = words[0].length();
        int totalLen = numWords * wordLen;

        if (n < totalLen) return {};

        unordered_map<string, int> wordCount;
        for (string& w : words) {
            wordCount[w]++;
        }

        vector<int> ans;

        // Try every possible word alignment offset
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int count = 0;
            unordered_map<string, int> currentCount;

            for (int right = offset; right <= n - wordLen; right += wordLen) {
                string word = s.substr(right, wordLen);

                if (wordCount.find(word) != wordCount.end()) {
                    currentCount[word]++;
                    count++;

                    // Shrink window if word frequency exceeded
                    while (currentCount[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currentCount[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // Valid concatenation found
                    if (count == numWords) {
                        ans.push_back(left);
                    }
                } else {
                    currentCount.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};
