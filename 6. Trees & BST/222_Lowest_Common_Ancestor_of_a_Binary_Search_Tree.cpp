// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (BST Directional Search)
// ==========================================
// Time Complexity  : O(h)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. curr = root.
2. While curr != nullptr:
     if p->val < curr->val && q->val < curr->val -> curr = curr->left
     else if p->val > curr->val && q->val > curr->val -> curr = curr->right
     else -> return curr // Split point is the LCA
3. Return nullptr.
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while (curr != nullptr) {
            // Both nodes are in the left subtree
            if (p->val < curr->val && q->val < curr->val) {
                curr = curr->left;
            }
            // Both nodes are in the right subtree
            else if (p->val > curr->val && q->val > curr->val) {
                curr = curr->right;
            }
            // Split occurs, curr is the lowest common ancestor
            else {
                return curr;
            }
        }

        return nullptr;
    }
};
