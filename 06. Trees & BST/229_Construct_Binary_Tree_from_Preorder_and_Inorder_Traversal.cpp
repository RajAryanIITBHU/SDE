// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <iostream>
#include <vector>
#include <unordered_map>

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
// 1. OPTIMAL APPROACH (Hash Map + Divide and Conquer)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Build inorderMap: val -> inorder_index.
2. Helper build(preStart, inStart, inEnd):
     if preStart > preorder.size() - 1 || inStart > inEnd return nullptr
     rootVal = preorder[preStart]
     root = new TreeNode(rootVal)
     inRootIdx = inorderMap[rootVal]
     numsLeft = inRootIdx - inStart
     root->left = build(preStart + 1, inStart, inRootIdx - 1)
     root->right = build(preStart + numsLeft + 1, inRootIdx + 1, inEnd)
     return root
3. Return build(0, 0, inorder.size() - 1).
*/

class Solution {
private:
    unordered_map<int, int> inMap;

    TreeNode* build(vector<int>& preorder, int preStart, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIdx = inMap[rootVal];
        int numsLeft = inRootIdx - inStart;

        root->left = build(preorder, preStart + 1, inStart, inRootIdx - 1);
        root->right = build(preorder, preStart + numsLeft + 1, inRootIdx + 1, inEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        return build(preorder, 0, 0, n - 1);
    }
};
