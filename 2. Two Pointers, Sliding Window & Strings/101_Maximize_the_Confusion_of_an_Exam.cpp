// Link: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sliding Window: Max Consecutive Char with <= K Flips)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper maxConsecutive(targetChar):
     left = 0, flips = 0, maxLen = 0
     For right from 0 to n-1:
         if answerKey[right] != targetChar -> flips++
         While flips > k:
             if answerKey[left] != targetChar -> flips--
             left++
         maxLen = max(maxLen, right - left + 1)
     return maxLen
2. Return max(maxConsecutive('T'), maxConsecutive('F')).
*/

class Solution {
private:
    int maxConsecutive(string& answerKey, int k, char targetChar) {
        int n = answerKey.length();
        int left = 0;
        int flips = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            if (answerKey[right] != targetChar) {
                flips++;
            }

            while (flips > k) {
                if (answerKey[left] != targetChar) {
                    flips--;
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutive(answerKey, k, 'T'), maxConsecutive(answerKey, k, 'F'));
    }
};
