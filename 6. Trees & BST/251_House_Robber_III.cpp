// Link: https://leetcode.com/problems/house-robber-iii/

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
// 1. OPTIMAL APPROACH (Tree DP: Rob / Do Not Rob Pair)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h)
/*
PSEUDOCODE:
1. Helper robHelper(root): returns pair<int, int> {robThisNode, notRobThisNode}.
     if root == nullptr return {0, 0}
     left = robHelper(root->left)
     right = robHelper(root->right)
     
     robThis = root->val + left.second + right.second
     notRobThis = max(left.first, left.second) + max(right.first, right.second)
     
     return {robThis, notRobThis}
2. res = robHelper(root).
3. Return max(res.first, res.second).
*/

class Solution {
private:
    pair<int, int> robHelper(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0}; // {rob, notRob}
        }

        auto left = robHelper(root->left);
        auto right = robHelper(root->right);

        // If we rob current house, we cannot rob children
        int robThis = root->val + left.second + right.second;

        // If we do not rob current house, we can choose to rob or not rob children
        int notRobThis = max(left.first, left.second) + max(right.first, right.second);

        return {robThis, notRobThis};
    }

public:
    int rob(TreeNode* root) {
        auto ans = robHelper(root);
        return max(ans.first, ans.second);
    }
};
