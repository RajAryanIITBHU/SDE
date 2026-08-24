// Link: https://leetcode.com/problems/symmetric-tree/

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
// 1. OPTIMAL APPROACH (Mirror DFS Helper)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h)
/*
PSEUDOCODE:
1. Helper isMirror(t1, t2):
     if t1 == nullptr && t2 == nullptr return true
     if t1 == nullptr || t2 == nullptr return false
     if t1->val != t2->val return false
     return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left)
2. Return root == nullptr || isMirror(root->left, root->right).
*/

class Solution {
private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return true;
        if (t1 == nullptr || t2 == nullptr) return false;

        if (t1->val != t2->val) return false;

        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
};
