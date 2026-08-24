/*
 * ============================================================================
 * Concept: String Parsing & Transformations
 * Subtopic: Two Pointers, Sliding Window & Strings
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * String parsing tasks involve tokenizing words, reversing words in-place, handling spaces, and performing string compression.
Idiomatic C++ uses `std::stringstream`, `std::reverse`, and in-place two-pointer scans.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) - linear traversal.
 * - Space Complexity: O(1) auxiliary space for in-place string modifications.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Reversing words in a sentence while truncating extra spaces.
- String Compression (Run Length Encoding in-place).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Reverse Words in a String (LC 151).
2. String Compression (LC 443).
3. Valid Number / IP Address Parsing.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Reverse Words in a String (LC 151)
string reverseWords(string s) {
    stringstream ss(s);
    string word, result = "";
    vector<string> words;
    while (ss >> word) words.push_back(word);
    
    for (int i = (int)words.size() - 1; i >= 0; --i) {
        result += words[i] + (i == 0 ? "" : " ");
    }
    return result;
}

int main() {
    string s = "  the sky  is blue ";
    cout << "Reversed Words: '" << reverseWords(s) << "'\n";
    return 0;
}
