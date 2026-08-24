// Link: https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <iostream>
#include <vector>
#include <queue>

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
// 1. OPTIMAL APPROACH (BFS Queue)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. If root == nullptr return {}.
2. Initialize queue<TreeNode*> q, push root.
3. While !q.empty():
     levelSize = q.size()
     vector<int> currentLevel
     For i from 0 to levelSize - 1:
         node = q.front(), q.pop()
         currentLevel.push_back(node->val)
         if node->left != nullptr -> q.push(node->left)
         if node->right != nullptr -> q.push(node->right)
     ans.push_back(currentLevel)
4. Return ans.
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                currentLevel.push_back(node->val);

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            ans.push_back(currentLevel);
        }

        return ans;
    }
};
