// Link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Offline Query Sorting + Binary 32-Bit Trie)
// ==========================================
// Time Complexity  : O(N log N + Q log Q + (N + Q) * 32)
// Space Complexity : O(N * 32 + Q)
/*
PSEUDOCODE:
1. Augment queries with original index: {m_i, x_i, originalIndex}.
2. Sort nums ascending, sort queries by m_i ascending.
3. Binary Trie supporting bit insertions from bit 31 down to 0 and max XOR query.
4. numIdx = 0, ans array of size Q.
5. For each query {m, x, origIdx}:
     While numIdx < nums.size() && nums[numIdx] <= m:
         insert nums[numIdx] into Trie
         numIdx++
     if Trie is empty: ans[origIdx] = -1
     else: ans[origIdx] = queryMaxXOR(x)
6. Return ans.
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

    struct QueryInfo {
        int m;
        int x;
        int idx;
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

    int getMaxXOR(TrieNode* root, int x) {
        TrieNode* curr = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int oppositeBit = 1 - bit;

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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        int qSize = queries.size();
        vector<QueryInfo> sortedQueries(qSize);
        for (int i = 0; i < qSize; i++) {
            sortedQueries[i] = {queries[i][1], queries[i][0], i};
        }

        sort(sortedQueries.begin(), sortedQueries.end(), [](const QueryInfo& a, const QueryInfo& b) {
            return a.m < b.m;
        });

        TrieNode* root = new TrieNode();
        vector<int> ans(qSize);
        int numIdx = 0;
        int n = nums.size();

        for (const auto& q : sortedQueries) {
            // Insert all elements from nums that are <= m into the Trie
            while (numIdx < n && nums[numIdx] <= q.m) {
                insert(root, nums[numIdx]);
                numIdx++;
            }

            if (numIdx == 0) {
                ans[q.idx] = -1; // No element <= m in nums
            } else {
                ans[q.idx] = getMaxXOR(root, q.x);
            }
        }

        return ans;
    }
};
