/*
 * ============================================================================
 * Concept: KMP Algorithm & Rabin-Karp Rolling Hash
 * Subtopic: Two Pointers, Sliding Window & Strings
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * KMP (Knuth-Morris-Pratt) pattern matching precomputes a Prefix Function array (`LPS` - Longest Proper Prefix which is also Suffix) in O(M) time to search pattern P in text T in O(N) time without backtracking.
Rabin-Karp uses a rolling hash function `hash = (hash * base + char) % mod` to match patterns in expected O(N + M) time.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N + M) matching time.
 * - Space Complexity: O(M) space for LPS array or hash state.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - String matching / Substring search (`indexOf` or `find`).
- Finding repeated substring patterns (LC 459).
- Multi-pattern search or 2D grid pattern matching.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Find Index of First Occurrence in String (LC 28).
2. Repeated Substring Pattern (LC 459).
3. Shortest Palindrome (KMP LPS array on `s + '#' + rev(s)`).
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Compute KMP Longest Prefix Suffix (LPS) Table
vector<int> computeLPS(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP Search
int strStrKMP(string haystack, string needle) {
    if (needle.empty()) return 0;
    int n = haystack.length(), m = needle.length();
    vector<int> lps = computeLPS(needle);
    int i = 0, j = 0;

    while (i < n) {
        if (haystack[i] == needle[j]) {
            i++; j++;
        }
        if (j == m) return i - j; // Match found
        else if (i < n && haystack[i] != needle[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return -1;
}

int main() {
    string text = "sadbutsad", pattern = "sad";
    cout << "Pattern found at index: " << strStrKMP(text, pattern) << "\n";
    return 0;
}
