// Link: https://leetcode.com/problems/search-in-a-binary-search-tree/

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
// 1. OPTIMAL APPROACH (Iterative BST Search)
// ==========================================
// Time Complexity  : O(h)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. curr = root.
2. While curr != nullptr && curr->val != val:
     if val < curr->val -> curr = curr->left
     else -> curr = curr->right
3. Return curr.
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;

        while (curr != nullptr && curr->val != val) {
            if (val < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return curr;
    }
};
