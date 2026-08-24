// Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
// 1. OPTIMAL APPROACH (BFS Queue with Direction Toggle)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. If root == nullptr return {}.
2. Initialize queue<TreeNode*> q, push root, leftToRight = true.
3. While !q.empty():
     levelSize = q.size()
     vector<int> currentLevel(levelSize)
     For i from 0 to levelSize - 1:
         node = q.front(), q.pop()
         idx = leftToRight ? i : (levelSize - 1 - i)
         currentLevel[idx] = node->val
         if node->left != nullptr -> q.push(node->left)
         if node->right != nullptr -> q.push(node->right)
     leftToRight = !leftToRight
     ans.push_back(currentLevel)
4. Return ans.
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> currentLevel(sz);

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Determine position based on zigzag direction
                int idx = leftToRight ? i : (sz - 1 - i);
                currentLevel[idx] = node->val;

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            leftToRight = !leftToRight;
            ans.push_back(currentLevel);
        }

        return ans;
    }
};
