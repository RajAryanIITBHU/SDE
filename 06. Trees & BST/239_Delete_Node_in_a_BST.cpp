// Link: https://leetcode.com/problems/delete-node-in-a-bst/

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
// 1. OPTIMAL APPROACH (BST Search + Inorder Successor Replacement)
// ==========================================
// Time Complexity  : O(h)
// Space Complexity : O(h) recursion stack
/*
PSEUDOCODE:
1. If root == nullptr return nullptr.
2. If key < root->val: root->left = deleteNode(root->left, key)
3. Else if key > root->val: root->right = deleteNode(root->right, key)
4. Else: (Node to delete found)
     if root->left == nullptr:
         temp = root->right, delete root, return temp
     else if root->right == nullptr:
         temp = root->left, delete root, return temp
     else:
         // Find inorder successor (min node in right subtree)
         succ = root->right
         While succ->left != nullptr: succ = succ->left
         root->val = succ->val
         root->right = deleteNode(root->right, succ->val)
5. Return root.
*/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Case 1 & 2: One child or no child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children - find inorder successor
            TreeNode* succ = root->right;
            while (succ->left != nullptr) {
                succ = succ->left;
            }

            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }

        return root;
    }
};
