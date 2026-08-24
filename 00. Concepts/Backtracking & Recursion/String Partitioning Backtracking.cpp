/*
 * ============================================================================
 * Concept: String Partitioning Backtracking
 * Subtopic: Backtracking & Recursion
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Partitions a string into valid substrings.
Iterate end index `i` from `start` to `s.length() - 1`. If subsegment `s[start...i]` is valid (e.g. palindrome), add to current path and recurse `backtrack(i+1)`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N * 2^N) time complexity.
 * - Space Complexity: O(N) recursion depth space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Palindrome Partitioning (LC 131).
- Restore IP Addresses (LC 93).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Palindrome Partitioning (LC 131).
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(const string& s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

void backtrackPalin(int start, const string& s, vector<string>& current, vector<vector<string>>& result) {
    if (start == (int)s.length()) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < (int)s.length(); ++i) {
        if (isPalindrome(s, start, i)) {
            current.push_back(s.substr(start, i - start + 1));
            backtrackPalin(i + 1, s, current, result);
            current.pop_back(); // Backtrack
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> current;
    backtrackPalin(0, s, current, result);
    return result;
}

int main() {
    auto res = partition("aab");
    cout << "Partition Count: " << res.size() << "\n"; // 2 ([a,a,b], [aa,b])
    return 0;
}
