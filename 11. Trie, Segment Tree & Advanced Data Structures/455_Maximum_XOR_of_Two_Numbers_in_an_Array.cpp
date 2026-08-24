// Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary 32-Bit Trie)
// ==========================================
// Time Complexity  : O(32 * n) = O(n)
// Space Complexity : O(32 * n) = O(n)
/*
PSEUDOCODE:
1. Binary Trie with children[2] (for bits 0 and 1).
2. Insert each num bit by bit from bit 31 down to bit 0.
3. For each num, query Trie to find the maximum possible XOR by greedily following the opposite bit (1 - bit).
4. Return maxXOR.
*/

class Solution {
private:
    struct TrieNode {
        TrieNode* children[2];
        TrieNode() {
            children[0] = nullptr;
            children[1] = nullptr;
        }
    };

    void insert(TrieNode* root, int num) {
        TrieNode* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (curr->children[bit] == nullptr) {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
    }

    int getMaxXOR(TrieNode* root, int num) {
        TrieNode* curr = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;

            // Greedily pick the opposite bit if available to maximize XOR
            if (curr->children[oppositeBit] != nullptr) {
                maxXor |= (1 << i);
                curr = curr->children[oppositeBit];
            } else {
                curr = curr->children[bit];
            }
        }

        return maxXor;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();

        for (int num : nums) {
            insert(root, num);
        }

        int maxResult = 0;
        for (int num : nums) {
            maxResult = max(maxResult, getMaxXOR(root, num));
        }

        return maxResult;
    }
};
