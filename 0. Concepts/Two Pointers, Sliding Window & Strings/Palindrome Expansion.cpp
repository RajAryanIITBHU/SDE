/*
 * ============================================================================
 * Concept: Expand Around Center (Palindromes)
 * Subtopic: Two Pointers, Sliding Window & Strings
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Finds palindromic substrings by expanding outward from potential centers.
A string of length N has `2*N - 1` possible centers (N single-char centers for odd length, N-1 double-char centers for even length).
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N^2) time complexity.
 * - Space Complexity: O(1) auxiliary space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Finding Longest Palindromic Substring (LC 5).
- Counting total Palindromic Substrings (LC 647).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Longest Palindromic Substring (LC 5).
2. Palindromic Substrings (LC 647).
3. Manacher's Algorithm (O(N) advanced variant for linear time palindrome search).
 */

#include <iostream>
#include <string>

using namespace std;

int expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < (int)s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; // length of palindrome
}

string longestPalindrome(string s) {
    if (s.empty()) return "";
    int start = 0, max_len = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
        int len1 = expandAroundCenter(s, i, i);     // Odd length
        int len2 = expandAroundCenter(s, i, i + 1); // Even length
        int len = max(len1, len2);
        if (len > max_len) {
            max_len = len;
            start = i - (len - 1) / 2;
        }
    }
    return s.substr(start, max_len);
}

int main() {
    string s = "babad";
    cout << "Longest Palindrome: " << longestPalindrome(s) << "\n";
    return 0;
}
