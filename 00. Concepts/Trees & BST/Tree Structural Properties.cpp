/*
 * ============================================================================
 * Concept: Tree Structural Properties (Depth, Height, Balance, Diameter)
 * Subtopic: Trees & BST
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Computes fundamental tree properties recursively bottom-up:
1. Max Depth: `1 + max(depth(left), depth(right))`
2. Balanced Tree: `abs(height(left) - height(right)) <= 1` at every node.
3. Diameter: Max path length between any two nodes `max(diameter, height(left) + height(right))`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time complexity.
 * - Space Complexity: O(H) recursion stack space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Maximum Depth of Binary Tree (LC 104).
- Balanced Binary Tree (LC 110).
- Diameter of Binary Tree (LC 543).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Diameter of Binary Tree.
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int height(TreeNode* node, int& diameter) {
    if (!node) return 0;
    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    cout << "Diameter: " << diameterOfBinaryTree(root) << "\n";
    return 0;
}
