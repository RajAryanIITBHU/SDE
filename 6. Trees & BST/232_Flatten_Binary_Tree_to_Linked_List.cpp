// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
// 1. OPTIMAL APPROACH (Morris-like In-Place Flattening)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. curr = root.
2. While curr != nullptr:
     if curr->left != nullptr:
         Find rightmost node in left subtree: prev = curr->left
         While prev->right != nullptr: prev = prev->right
         prev->right = curr->right
         curr->right = curr->left
         curr->left = nullptr
     curr = curr->right
*/

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // Find predecessor in left subtree
                TreeNode* prev = curr->left;
                while (prev->right != nullptr) {
                    prev = prev->right;
                }

                // Connect predecessor to current right subtree
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }

            curr = curr->right;
        }
    }
};
