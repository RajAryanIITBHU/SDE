// Link: https://leetcode.com/problems/binary-tree-right-side-view/

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
// 1. OPTIMAL APPROACH (BFS Level Order - Last Element of Each Level)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. If root == nullptr return {}.
2. Initialize queue<TreeNode*> q, push root.
3. While !q.empty():
     levelSize = q.size()
     For i from 0 to levelSize - 1:
         node = q.front(), q.pop()
         if i == levelSize - 1 -> ans.push_back(node->val) // Rightmost node
         if node->left != nullptr -> q.push(node->left)
         if node->right != nullptr -> q.push(node->right)
4. Return ans.
*/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                // The last element processed in this level is visible from the right
                if (i == sz - 1) {
                    ans.push_back(node->val);
                }

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
        }

        return ans;
    }
};
