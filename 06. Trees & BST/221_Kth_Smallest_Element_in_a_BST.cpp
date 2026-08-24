// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
// 1. OPTIMAL APPROACH (Inorder Traversal Early Stop)
// ==========================================
// Time Complexity  : O(h + k)
// Space Complexity : O(h)
/*
PSEUDOCODE:
1. Helper inorder(root, k, ans):
     if root == nullptr || k == 0 return
     inorder(root->left, k, ans)
     k--
     if k == 0:
         ans = root->val
         return
     inorder(root->right, k, ans)
2. Return ans.
*/

class Solution {
private:
    void inorder(TreeNode* root, int& k, int& ans) {
        if (root == nullptr || k <= 0) return;

        inorder(root->left, k, ans);

        k--;
        if (k == 0) {
            ans = root->val;
            return;
        }

        inorder(root->right, k, ans);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};
