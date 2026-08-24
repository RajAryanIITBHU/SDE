// Link: https://leetcode.com/problems/valid-palindrome-ii/

#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Two Pointers with At Most 1 Deletion)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper isPal(s, left, right): checks if substring s[left..right] is palindrome.
2. Initialize left = 0, right = n - 1.
3. While left < right:
     if s[left] != s[right]:
         // Try skipping either left char or right char
         return isPal(s, left + 1, right) || isPal(s, left, right - 1)
     left++, right--
4. Return true.
*/

class Solution {
private:
    bool isPal(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = (int)s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                // Check if skipping left char or right char results in valid palindrome
                return isPal(s, left + 1, right) || isPal(s, left, right - 1);
            }
            left++;
            right--;
        }

        return true;
    }
};
