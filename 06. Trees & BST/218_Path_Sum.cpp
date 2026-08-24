// Link: https://leetcode.com/problems/path-sum/

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
// 1. OPTIMAL APPROACH (DFS Target Subtraction)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h)
/*
PSEUDOCODE:
1. If root == nullptr return false.
2. If root->left == nullptr && root->right == nullptr:
     return targetSum == root->val
3. rem = targetSum - root->val.
4. Return hasPathSum(root->left, rem) || hasPathSum(root->right, rem).
*/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;

        // Leaf node check
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }

        int rem = targetSum - root->val;
        return hasPathSum(root->left, rem) || hasPathSum(root->right, rem);
    }
};
