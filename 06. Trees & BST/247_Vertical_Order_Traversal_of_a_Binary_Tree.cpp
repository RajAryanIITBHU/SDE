// Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

#include <iostream>
#include <vector>
#include <map>
#include <set>
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
// 1. OPTIMAL APPROACH (BFS with Nested Coordinate Mapping)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain nodesMap: col -> row -> multiset<val> (keeps sorted order automatically).
2. Queue storing {node, {row, col}}, push {root, {0, 0}}.
3. While !q.empty():
     {node, {r, c}} = q.front(), q.pop()
     nodesMap[c][r].insert(node->val)
     if node->left != nullptr -> q.push({node->left, {r + 1, c - 1}})
     if node->right != nullptr -> q.push({node->right, {r + 1, c + 1}})
4. Traverse nodesMap column by column, row by row, appending multiset contents to column vector.
5. Return ans.
*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == nullptr) return {};

        // map<col, map<row, multiset<val>>>
        map<int, map<int, multiset<int>>> nodesMap;
        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {row, col}}

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int r = p.second.first;
            int c = p.second.second;

            nodesMap[c][r].insert(node->val);

            if (node->left != nullptr) {
                q.push({node->left, {r + 1, c - 1}});
            }
            if (node->right != nullptr) {
                q.push({node->right, {r + 1, c + 1}});
            }
        }

        vector<vector<int>> ans;
        for (auto& colPair : nodesMap) {
            vector<int> col;
            for (auto& rowPair : colPair.second) {
                col.insert(col.end(), rowPair.second.begin(), rowPair.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
