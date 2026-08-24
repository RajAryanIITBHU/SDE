// Link: https://leetcode.com/problems/diameter-of-binary-tree/

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
// 1. OPTIMAL APPROACH (Bottom-Up DFS Diameter)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h)
/*
PSEUDOCODE:
1. Helper height(root, maxDiameter):
     if root == nullptr return 0
     lh = height(root->left, maxDiameter)
     rh = height(root->right, maxDiameter)
     maxDiameter = max(maxDiameter, lh + rh)
     return 1 + max(lh, rh)
2. Return maxDiameter.
*/

class Solution {
private:
    int height(TreeNode* root, int& maxDiameter) {
        if (root == nullptr) return 0;

        int lh = height(root->left, maxDiameter);
        int rh = height(root->right, maxDiameter);

        maxDiameter = max(maxDiameter, lh + rh);

        return 1 + max(lh, rh);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        height(root, maxDiameter);
        return maxDiameter;
    }
};
