// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

#include <iostream>
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
// 1. OPTIMAL APPROACH (Bottom-Up DFS Max Gain)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h)
/*
PSEUDOCODE:
1. Helper maxGain(root, maxSum):
     if root == nullptr return 0
     leftGain = max(0, maxGain(root->left, maxSum))
     rightGain = max(0, maxGain(root->right, maxSum))
     // Current path sum using root as turnaround apex
     currentPath = root->val + leftGain + rightGain
     maxSum = max(maxSum, currentPath)
     return root->val + max(leftGain, rightGain)
2. Return maxSum.
*/

class Solution {
private:
    int maxGain(TreeNode* root, int& maxSum) {
        if (root == nullptr) return 0;

        // Ignore negative path sums by taking max with 0
        int leftGain = max(0, maxGain(root->left, maxSum));
        int rightGain = max(0, maxGain(root->right, maxSum));

        // Max path passing through current node
        int currentPath = root->val + leftGain + rightGain;
        maxSum = max(maxSum, currentPath);

        // Return max one-way branch gain
        return root->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }
};
