// Link: https://leetcode.com/problems/reverse-vowels-of-a-string/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Two Pointers)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) in-place
/*
PSEUDOCODE:
1. Helper isVowel(char c): checks if c is 'a','e','i','o','u','A','E','I','O','U'.
2. Initialize left = 0, right = n - 1.
3. While left < right:
     While left < right and !isVowel(s[left]) -> left++
     While left < right and !isVowel(s[right]) -> right--
     swap(s[left], s[right])
     left++, right--
4. Return s.
*/

class Solution {
private:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

public:
    string reverseVowels(string s) {
        int left = 0;
        int right = (int)s.length() - 1;

        while (left < right) {
            while (left < right && !isVowel(s[left])) left++;
            while (left < right && !isVowel(s[right])) right--;

            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};
