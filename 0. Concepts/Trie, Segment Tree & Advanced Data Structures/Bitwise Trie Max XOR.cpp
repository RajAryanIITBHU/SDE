/*
 * ============================================================================
 * Concept: Bitwise Trie (Maximum XOR of Two Numbers)
 * Subtopic: Trie, Segment Tree & Advanced Data Structures
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Binary Trie where each node branches on bit `0` or bit `1` of 32-bit integers.
To find maximum XOR for `X`: For each bit of X from bit 31 down to 0, greedily traverse the opposite bit branch `(1 - bit)` if it exists!
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(32 * N) ~ O(N) time complexity.
 * - Space Complexity: O(32 * N) ~ O(N) space complexity.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Maximum XOR of Two Numbers in an Array (LC 421).
- Maximum XOR With an Element From Array (LC 1707).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Maximum XOR Pair in Array (LC 421).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BitTrieNode {
public:
    BitTrieNode* children[2] = {};
};

class BitTrie {
    BitTrieNode* root = new BitTrieNode();
public:
    void insert(int num) {
        BitTrieNode* curr = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!curr->children[bit]) curr->children[bit] = new BitTrieNode();
            curr = curr->children[bit];
        }
    }

    int getMaxXOR(int num) {
        BitTrieNode* curr = root;
        int max_xor = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int opp_bit = 1 - bit;
            if (curr->children[opp_bit]) {
                max_xor |= (1 << i);
                curr = curr->children[opp_bit];
            } else {
                curr = curr->children[bit];
            }
        }
        return max_xor;
    }
};

int findMaximumXOR(vector<int>& nums) {
    BitTrie trie;
    for (int num : nums) trie.insert(num);
    int maxXOR = 0;
    for (int num : nums) maxXOR = max(maxXOR, trie.getMaxXOR(num));
    return maxXOR;
}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << "Max XOR Pair: " << findMaximumXOR(nums) << "\n"; // 28 (5 ^ 25)
    return 0;
}
