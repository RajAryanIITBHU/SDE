// Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
// 1. OPTIMAL APPROACH (BFS Level Order - First Leaf Node Encountered)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. If root == nullptr return 0.
2. Initialize queue<TreeNode*> q, push root, depth = 1.
3. While !q.empty():
     levelSize = q.size()
     For i from 0 to levelSize - 1:
         node = q.front(), q.pop()
         if node->left == nullptr && node->right == nullptr:
             return depth // First leaf reached!
         if node->left != nullptr -> q.push(node->left)
         if node->right != nullptr -> q.push(node->right)
     depth++
4. Return depth.
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                // If leaf node reached, return current depth immediately
                if (node->left == nullptr && node->right == nullptr) {
                    return depth;
                }

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            depth++;
        }

        return depth;
    }
};
