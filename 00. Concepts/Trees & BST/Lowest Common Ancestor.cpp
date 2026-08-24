/*
 * ============================================================================
 * Concept: Lowest Common Ancestor (LCA)
 * Subtopic: Trees & BST
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Finds the lowest common ancestor node of two target nodes P and Q.
1. LCA in BST (LC 235): If both P and Q are smaller than root, go left; if both greater, go right; else root IS the LCA!
2. LCA in Binary Tree (LC 236): Post-order DFS. If current node is P or Q, return current node. If both left and right calls return non-null, current node IS the LCA.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(H) for BST, O(N) for general Binary Tree.
 * - Space Complexity: O(H) stack space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Lowest Common Ancestor of a BST (LC 235).
- Lowest Common Ancestor of a Binary Tree (LC 236).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. LCA in General Binary Tree.
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root;
    return left ? left : right;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    auto lca = lowestCommonAncestor(root, root->left, root->right);
    cout << "LCA Val: " << lca->val << "\n"; // 3
    return 0;
}
