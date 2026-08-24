// Link: https://leetcode.com/problems/path-sum-ii/

#include <iostream>
#include <vector>

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
// 1. OPTIMAL APPROACH (DFS Backtracking Path Collection)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h) recursion stack + O(n) path storage
/*
PSEUDOCODE:
1. Helper dfs(root, targetSum, currentPath, ans):
     if root == nullptr return
     currentPath.push_back(root->val)
     if root->left == nullptr && root->right == nullptr && targetSum == root->val:
         ans.push_back(currentPath)
     dfs(root->left, targetSum - root->val, currentPath, ans)
     dfs(root->right, targetSum - root->val, currentPath, ans)
     currentPath.pop_back() // Backtrack
2. Return ans.
*/

class Solution {
private:
    void dfs(TreeNode* root, int targetSum, vector<int>& currentPath, vector<vector<int>>& ans) {
        if (root == nullptr) return;

        currentPath.push_back(root->val);

        // Check if leaf node matches remaining targetSum
        if (root->left == nullptr && root->right == nullptr && targetSum == root->val) {
            ans.push_back(currentPath);
        }

        dfs(root->left, targetSum - root->val, currentPath, ans);
        dfs(root->right, targetSum - root->val, currentPath, ans);

        currentPath.pop_back(); // Backtrack
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currentPath;
        dfs(root, targetSum, currentPath, ans);
        return ans;
    }
};
