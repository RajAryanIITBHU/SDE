// Link: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

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
// 1. OPTIMAL APPROACH (DFS Step Counter with Direction Tracking)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h)
/*
PSEUDOCODE:
1. Helper dfs(node, goLeft, steps, maxSteps):
     if node == nullptr return
     maxSteps = max(maxSteps, steps)
     if goLeft:
         dfs(node->left, false, steps + 1, maxSteps) // Continue zigzag left
         dfs(node->right, true, 1, maxSteps) // Restart zigzag right
     else:
         dfs(node->right, true, steps + 1, maxSteps) // Continue zigzag right
         dfs(node->left, false, 1, maxSteps) // Restart zigzag left
2. dfs(root, true, 0, maxSteps), dfs(root, false, 0, maxSteps).
3. Return maxSteps.
*/

class Solution {
private:
    void dfs(TreeNode* node, bool goLeft, int steps, int& maxSteps) {
        if (node == nullptr) return;

        maxSteps = max(maxSteps, steps);

        if (goLeft) {
            dfs(node->left, false, steps + 1, maxSteps); // Continue zigzag to left
            dfs(node->right, true, 1, maxSteps);          // Restart zigzag to right
        } else {
            dfs(node->right, true, steps + 1, maxSteps); // Continue zigzag to right
            dfs(node->left, false, 1, maxSteps);         // Restart zigzag to left
        }
    }

public:
    int longestZigZag(TreeNode* root) {
        int maxSteps = 0;
        dfs(root, true, 0, maxSteps);
        dfs(root, false, 0, maxSteps);
        return maxSteps;
    }
};
