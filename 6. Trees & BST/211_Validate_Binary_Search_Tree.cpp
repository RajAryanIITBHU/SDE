// Link: https://leetcode.com/problems/validate-binary-search-tree/

#include <iostream>
#include <climits>

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
// 1. OPTIMAL APPROACH (DFS Valid Value Range)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h), where h is tree height
/*
PSEUDOCODE:
1. Helper isValid(root, minVal, maxVal):
     if root == nullptr return true
     if root->val <= minVal || root->val >= maxVal return false
     return isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal)
2. Return isValid(root, LONG_MIN, LONG_MAX).
*/

class Solution {
private:
    bool isValid(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr) return true;

        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }

        return isValid(root->left, minVal, root->val) && 
               isValid(root->right, root->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};