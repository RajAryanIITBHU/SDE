// Link: https://leetcode.com/problems/maximum-width-of-binary-tree/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (BFS Queue with Normalized Indexing)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. If root == nullptr return 0.
2. Initialize queue<pair<TreeNode*, unsigned long long>> q, push {root, 0}.
3. maxWidth = 0.
4. While !q.empty():
     levelSize = q.size(), minIdx = q.front().second
     firstIdx = 0, lastIdx = 0
     For i from 0 to levelSize - 1:
         {node, currIdx} = q.front(), q.pop()
         normalizedIdx = currIdx - minIdx // Prevents integer overflow
         if i == 0 -> firstIdx = normalizedIdx
         if i == levelSize - 1 -> lastIdx = normalizedIdx
         if node->left != nullptr -> q.push({node->left, 2 * normalizedIdx + 1})
         if node->right != nullptr -> q.push({node->right, 2 * normalizedIdx + 2})
     maxWidth = max(maxWidth, (int)(lastIdx - firstIdx + 1))
5. Return maxWidth.
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int sz = q.size();
            unsigned long long minIdx = q.front().second;
            unsigned long long firstIdx = 0, lastIdx = 0;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front().first;
                unsigned long long currIdx = q.front().second - minIdx; // Normalize to 0
                q.pop();

                if (i == 0) firstIdx = currIdx;
                if (i == sz - 1) lastIdx = currIdx;

                if (node->left != nullptr) {
                    q.push({node->left, 2 * currIdx + 1});
                }
                if (node->right != nullptr) {
                    q.push({node->right, 2 * currIdx + 2});
                }
            }

            maxWidth = max(maxWidth, (int)(lastIdx - firstIdx + 1));
        }

        return maxWidth;
    }
};
