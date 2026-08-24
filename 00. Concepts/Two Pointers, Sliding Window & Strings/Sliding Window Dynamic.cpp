/*
 * ============================================================================
 * Concept: Sliding Window (Dynamic / Shrinkable)
 * Subtopic: Two Pointers, Sliding Window & Strings
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Maintains a dynamic window `[left, right]` that expands by moving `right` pointer and shrinks by moving `left` pointer when a constraint is violated (or to minimize window size).
Used for finding longest/shortest contiguous subarrays satisfying a condition.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) - each element is processed at most twice (by left and right pointers).
 * - Space Complexity: O(K) - hash map or frequency array for window characters.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - "Longest / Shortest substring/subarray with condition X".
- Minimum Window Substring, Longest Substring Without Repeating Characters.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Longest Substring Without Repeating Characters (LC 3).
2. Minimum Window Substring (LC 76).
3. Fruit Into Baskets / At Most K Distinct Characters (LC 904).
4. Max Consecutive Ones III (LC 1004).
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Longest Substring Without Repeating Characters (LC 3)
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> last_seen;
    int max_len = 0, left = 0;

    for (int right = 0; right < (int)s.length(); ++right) {
        char ch = s[right];
        if (last_seen.count(ch) && last_seen[ch] >= left) {
            left = last_seen[ch] + 1;
        }
        last_seen[ch] = right;
        max_len = max(max_len, right - left + 1);
    }
    return max_len;
}

int main() {
    string s = "abcabcbb";
    cout << "Longest Substring Len: " << lengthOfLongestSubstring(s) << "\n";
    return 0;
}
