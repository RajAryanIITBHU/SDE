/*
 * ============================================================================
 * Concept: Lexicographical Ordering & Alien Dictionary
 * Subtopic: Microsoft High-Frequency Real OA & GFG Interview Classics
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Verifies or reconstructs character precedence rules given a sorted dictionary of alien words.
Uses Pairwise Word Character Comparison + Directed Graph Construction + Topological Sort (Kahn's algorithm).
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(C) where C is total characters in all words.
 * - Space Complexity: O(V + E) space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Alien Dictionary (LC 269 / GFG).
- Verifying an Alien Dictionary (LC 953).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Verifying an Alien Dictionary (LC 953).
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> orderMap;
    for (int i = 0; i < (int)order.length(); ++i) orderMap[order[i]] = i;

    for (size_t i = 0; i < words.size() - 1; ++i) {
        string w1 = words[i], w2 = words[i + 1];
        bool foundDiff = false;
        for (size_t j = 0; j < min(w1.length(), w2.length()); ++j) {
            if (w1[j] != w2[j]) {
                if (orderMap[w1[j]] > orderMap[w2[j]]) return false;
                foundDiff = true;
                break;
            }
        }
        if (!foundDiff && w1.length() > w2.length()) return false;
    }
    return true;
}

int main() {
    vector<string> words = {"hello", "leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    cout << "Is Sorted: " << (isAlienSorted(words, order) ? "Yes" : "No") << "\n";
    return 0;
}
