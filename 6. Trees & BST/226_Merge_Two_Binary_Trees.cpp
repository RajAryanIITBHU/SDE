// Link: https://leetcode.com/problems/merge-two-binary-trees/

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
// 1. OPTIMAL APPROACH (Recursive DFS Tree Construction)
// ==========================================
// Time Complexity  : O(min(n, m))
// Space Complexity : O(min(h1, h2))
/*
PSEUDOCODE:
1. If root1 == nullptr return root2.
2. If root2 == nullptr return root1.
3. mergedNode = new TreeNode(root1->val + root2->val).
4. mergedNode->left = mergeTrees(root1->left, root2->left).
5. mergedNode->right = mergeTrees(root1->right, root2->right).
6. Return mergedNode.
*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;

        TreeNode* merged = new TreeNode(root1->val + root2->val);
        merged->left = mergeTrees(root1->left, root2->left);
        merged->right = mergeTrees(root1->right, root2->right);

        return merged;
    }
};
