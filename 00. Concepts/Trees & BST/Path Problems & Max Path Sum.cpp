/*
 * ============================================================================
 * Concept: Binary Tree Max Path Sum & Path Sums
 * Subtopic: Trees & BST
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Solves path sum problems on binary trees:
1. Path Sum (LC 112): Root-to-leaf path target.
2. Path Sum II (LC 113): Collect all root-to-leaf paths using backtracking.
3. Binary Tree Maximum Path Sum (LC 124): Any-to-any path sum `max_gain(node) = node->val + max(0, left) + max(0, right)`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time complexity.
 * - Space Complexity: O(H) recursion stack space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Binary Tree Maximum Path Sum (LC 124).
- Path Sum III (LC 437 - Prefix Sum + DFS).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Binary Tree Max Path Sum.
 */

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxPathGain(TreeNode* node, int& maxSum) {
    if (!node) return 0;
    int leftGain = max(0, maxPathGain(node->left, maxSum));
    int rightGain = max(0, maxPathGain(node->right, maxSum));
    
    maxSum = max(maxSum, node->val + leftGain + rightGain);
    return node->val + max(leftGain, rightGain);
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathGain(root, maxSum);
    return maxSum;
}

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << "Max Path Sum: " << maxPathSum(root) << "\n";
    return 0;
}
