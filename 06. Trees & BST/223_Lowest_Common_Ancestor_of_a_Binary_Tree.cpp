// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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
// 1. OPTIMAL APPROACH (Recursive DFS Divide and Conquer)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h)
/*
PSEUDOCODE:
1. If root == nullptr || root == p || root == q return root.
2. leftLCA = lowestCommonAncestor(root->left, p, q)
3. rightLCA = lowestCommonAncestor(root->right, p, q)
4. if leftLCA != nullptr && rightLCA != nullptr return root // p and q found in different subtrees
5. return leftLCA != nullptr ? leftLCA : rightLCA
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // If one node is in left subtree and one is in right subtree, root is the LCA
        if (leftLCA != nullptr && rightLCA != nullptr) {
            return root;
        }

        return (leftLCA != nullptr) ? leftLCA : rightLCA;
    }
};
