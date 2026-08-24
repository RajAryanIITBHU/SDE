// Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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
// 1. OPTIMAL APPROACH (BFS Level Order Max Tracking)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. If root == nullptr return {}.
2. Initialize queue<TreeNode*> q, push root, vector<int> ans.
3. While !q.empty():
     levelSize = q.size(), maxVal = INT_MIN
     For i from 0 to levelSize - 1:
         node = q.front(), q.pop()
         maxVal = max(maxVal, node->val)
         if node->left != nullptr -> q.push(node->left)
         if node->right != nullptr -> q.push(node->right)
     ans.push_back(maxVal)
4. Return ans.
*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            int maxVal = INT_MIN;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                maxVal = max(maxVal, node->val);

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            ans.push_back(maxVal);
        }

        return ans;
    }
};
