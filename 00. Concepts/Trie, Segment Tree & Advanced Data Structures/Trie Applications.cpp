/*
 * ============================================================================
 * Concept: Search Suggestions System (Trie + Autocomplete)
 * Subtopic: Trie, Segment Tree & Advanced Data Structures
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Applications of Trie for real-world autocomplete, top-3 prefix suggestions, and string replacement.
High Frequency Microsoft Question: Search Suggestions System (LC 1268).
Store up to 3 lexicographically smallest words at each TrieNode during insertion to answer queries in O(L) time!
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N * L + M) build and search time.
 * - Space Complexity: O(N * L) space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Search Suggestions System (LC 1268).
- Replace Words (LC 648).
- Map Sum Pairs (LC 677).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Search Suggestions System (LC 1268).
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    Node* children[26] = {};
    vector<string> suggestions;
};

class SearchSuggestions {
    Node* root = new Node();
public:
    void insert(const string& word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = new Node();
            curr = curr->children[idx];
            if (curr->suggestions.size() < 3) {
                curr->suggestions.push_back(word);
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end()); // Lexicographical sort first
        for (const string& p : products) insert(p);

        vector<vector<string>> result;
        Node* curr = root;
        for (char c : searchWord) {
            if (curr) curr = curr->children[c - 'a'];
            result.push_back(curr ? curr->suggestions : vector<string>());
        }
        return result;
    }
};

int main() {
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    SearchSuggestions sys;
    auto res = sys.suggestedProducts(products, "mouse");
    cout << "Suggestions for 'm': " << res[0].size() << "\n";
    return 0;
}
