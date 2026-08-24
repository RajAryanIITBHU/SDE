// Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
// 1. OPTIMAL APPROACH (Hash Map + Postorder Divide & Conquer)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Build inorderMap: val -> inorder_index.
2. Helper build(inStart, inEnd, postStart, postEnd):
     if inStart > inEnd || postStart > postEnd return nullptr
     rootVal = postorder[postEnd]
     root = new TreeNode(rootVal)
     inRootIdx = inMap[rootVal]
     numsLeft = inRootIdx - inStart
     root->left = build(inStart, inRootIdx - 1, postStart, postStart + numsLeft - 1)
     root->right = build(inRootIdx + 1, inEnd, postStart + numsLeft, postEnd - 1)
     return root
3. Return build(0, n - 1, 0, n - 1).
*/

class Solution {
private:
    unordered_map<int, int> inMap;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) return nullptr;

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIdx = inMap[rootVal];
        int numsLeft = inRootIdx - inStart;

        root->left = build(inorder, postorder, inStart, inRootIdx - 1, postStart, postStart + numsLeft - 1);
        root->right = build(inorder, postorder, inRootIdx + 1, inEnd, postStart + numsLeft, postEnd - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        return build(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};
