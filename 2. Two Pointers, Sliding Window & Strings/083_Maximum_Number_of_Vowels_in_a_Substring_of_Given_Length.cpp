// Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Fixed Sliding Window of Size K)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper isVowel(c): returns true for 'a', 'e', 'i', 'o', 'u'.
2. Count vowels in the first window of size k: vowelCount.
3. ans = vowelCount.
4. For i from k to n-1:
     if isVowel(s[i]) -> vowelCount++
     if isVowel(s[i - k]) -> vowelCount--
     ans = max(ans, vowelCount)
5. Return ans.
*/

class Solution {
private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int vowelCount = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) vowelCount++;
        }

        int ans = vowelCount;

        for (int i = k; i < n; i++) {
            if (isVowel(s[i])) vowelCount++;
            if (isVowel(s[i - k])) vowelCount--;

            ans = max(ans, vowelCount);
        }

        return ans;
    }
};
