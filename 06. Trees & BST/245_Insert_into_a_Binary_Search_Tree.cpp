// Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/

#include <iostream>

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
// 1. OPTIMAL APPROACH (Iterative Tree Traversal)
// ==========================================
// Time Complexity  : O(h)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If root == nullptr return new TreeNode(val).
2. curr = root.
3. While true:
     if val < curr->val:
         if curr->left != nullptr -> curr = curr->left
         else: curr->left = new TreeNode(val), break
     else:
         if curr->right != nullptr -> curr = curr->right
         else: curr->right = new TreeNode(val), break
4. Return root.
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);

        TreeNode* curr = root;

        while (true) {
            if (val < curr->val) {
                if (curr->left != nullptr) {
                    curr = curr->left;
                } else {
                    curr->left = new TreeNode(val);
                    break;
                }
            } else {
                if (curr->right != nullptr) {
                    curr = curr->right;
                } else {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};
