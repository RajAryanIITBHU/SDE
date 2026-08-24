// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/

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
// 1. OPTIMAL APPROACH (DFS with Existence Flags)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h)
/*
PSEUDOCODE:
1. Maintain foundP = false, foundQ = false.
2. Helper lca(root, p, q):
     if root == nullptr return nullptr
     left = lca(root->left, p, q)
     right = lca(root->right, p, q)
     if root == p:
         foundP = true
         return root
     if root == q:
         foundQ = true
         return root
     if left != nullptr && right != nullptr return root
     return left != nullptr ? left : right
3. res = lca(root, p, q)
4. Return (foundP && foundQ) ? res : nullptr.
*/

class Solution {
private:
    bool foundP = false;
    bool foundQ = false;

    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;

        TreeNode* left = dfs(root->left, p, q);
        TreeNode* right = dfs(root->right, p, q);

        if (root == p) {
            foundP = true;
            return root;
        }
        if (root == q) {
            foundQ = true;
            return root;
        }

        if (left != nullptr && right != nullptr) {
            return root;
        }

        return (left != nullptr) ? left : right;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = dfs(root, p, q);
        return (foundP && foundQ) ? ans : nullptr;
    }
};
