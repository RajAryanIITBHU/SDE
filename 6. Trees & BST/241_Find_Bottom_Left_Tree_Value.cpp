// Link: https://leetcode.com/problems/find-bottom-left-tree-value/

#include <iostream>
#include <queue>

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
// 1. OPTIMAL APPROACH (Right-to-Left BFS Queue)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize queue<TreeNode*> q, push root.
2. While !q.empty():
     node = q.front(), q.pop()
     // Push right child FIRST, then left child
     if node->right != nullptr -> q.push(node->right)
     if node->left != nullptr -> q.push(node->left)
3. The very last node popped from queue is the bottom-left node!
4. Return node->val.
*/

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node = nullptr;

        // Traverse right-to-left so the last element processed is bottom-left
        while (!q.empty()) {
            node = q.front();
            q.pop();

            if (node->right != nullptr) q.push(node->right);
            if (node->left != nullptr) q.push(node->left);
        }

        return node->val;
    }
};
