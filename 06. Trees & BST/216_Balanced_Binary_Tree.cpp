// Link: https://leetcode.com/problems/balanced-binary-tree/

#include <iostream>
#include <cmath>
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
// 1. OPTIMAL APPROACH (Bottom-Up DFS Height Check)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h)
/*
PSEUDOCODE:
1. Helper checkHeight(root):
     if root == nullptr return 0
     leftHeight = checkHeight(root->left)
     if leftHeight == -1 return -1
     rightHeight = checkHeight(root->right)
     if rightHeight == -1 return -1
     if abs(leftHeight - rightHeight) > 1 return -1
     return 1 + max(leftHeight, rightHeight)
2. Return checkHeight(root) != -1.
*/

class Solution {
private:
    int checkHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1;

        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // Unbalanced subtree
        }

        return 1 + max(leftHeight, rightHeight);
    }

public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
