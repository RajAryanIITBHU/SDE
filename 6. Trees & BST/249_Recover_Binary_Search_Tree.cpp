// Link: https://leetcode.com/problems/recover-binary-search-tree/

#include <iostream>
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
// 1. OPTIMAL APPROACH (Inorder Traversal Swapped Pointers Tracking)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h)
/*
PSEUDOCODE:
1. Maintain firstNode = nullptr, secondNode = nullptr, prevNode = new TreeNode(INT_MIN).
2. Helper inorder(root):
     if root == nullptr return
     inorder(root->left)
     if prevNode != nullptr && root->val < prevNode->val:
         if firstNode == nullptr:
             firstNode = prevNode
         secondNode = root // Will be overwritten if second disruption is found
     prevNode = root
     inorder(root->right)
3. Swap values: swap(firstNode->val, secondNode->val).
*/

class Solution {
private:
    TreeNode* firstNode = nullptr;
    TreeNode* secondNode = nullptr;
    TreeNode* prevNode = nullptr;

    void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);

        // Detect inversion in BST inorder property
        if (prevNode != nullptr && root->val < prevNode->val) {
            if (firstNode == nullptr) {
                firstNode = prevNode;
            }
            secondNode = root;
        }
        prevNode = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);

        // Swap the misplaced values
        if (firstNode != nullptr && secondNode != nullptr) {
            swap(firstNode->val, secondNode->val);
        }
    }
};
