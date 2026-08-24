// Link: https://leetcode.com/problems/binary-tree-cameras/

#include <iostream>

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
// 1. OPTIMAL APPROACH (Greedy Postorder DFS - 3 State Machine)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h)
/*
PSEUDOCODE:
State Definitions:
  0 -> Node is NOT covered
  1 -> Node HAS a camera
  2 -> Node is COVERED (no camera)

1. Helper dfs(root, cameras):
     if root == nullptr return 2 (null nodes are considered covered)
     left = dfs(root->left, cameras)
     right = dfs(root->right, cameras)
     
     if left == 0 || right == 0:
         cameras++
         return 1 // Must place a camera here to cover uncovered child
     
     if left == 1 || right == 1:
         return 2 // Covered by child's camera
     
     return 0 // Neither child has camera, this node is uncovered
2. If dfs(root, cameras) == 0 -> cameras++ (cover root)
3. Return cameras.
*/

class Solution {
private:
    // 0: Uncovered, 1: Has Camera, 2: Covered
    int dfs(TreeNode* root, int& cameras) {
        if (root == nullptr) return 2;

        int left = dfs(root->left, cameras);
        int right = dfs(root->right, cameras);

        // If any child is uncovered, this node must place a camera
        if (left == 0 || right == 0) {
            cameras++;
            return 1;
        }

        // If any child has a camera, this node is covered
        if (left == 1 || right == 1) {
            return 2;
        }

        // If both children are covered but have no camera, this node is uncovered
        return 0;
    }

public:
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        if (dfs(root, cameras) == 0) {
            cameras++; // If root is uncovered, place camera on root
        }
        return cameras;
    }
};
