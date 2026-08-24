// Link: https://leetcode.com/problems/binary-tree-paths/

#include <iostream>
#include <vector>
#include <string>

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
// 1. OPTIMAL APPROACH (DFS Backtracking Path Generation)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h) recursion stack
/*
PSEUDOCODE:
1. Helper dfs(root, path, ans):
     if root == nullptr return
     path += to_string(root->val)
     if root->left == nullptr && root->right == nullptr:
         ans.push_back(path)
         return
     path += "->"
     dfs(root->left, path, ans)
     dfs(root->right, path, ans)
2. Return ans.
*/

class Solution {
private:
    void dfs(TreeNode* root, string path, vector<string>& ans) {
        if (root == nullptr) return;

        path += to_string(root->val);

        // Leaf node reached
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
            return;
        }

        path += "->";
        if (root->left != nullptr) dfs(root->left, path, ans);
        if (root->right != nullptr) dfs(root->right, path, ans);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, "", ans);
        return ans;
    }
};
