/*
 * ============================================================================
 * Concept: BST Core Operations & Validation
 * Subtopic: Trees & BST
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Binary Search Tree property: For every node, `all left < node->val < all right`.
Operations:
1. Validate BST: Check range `(minVal, maxVal)` at each node.
2. Search, Insert, Delete node in BST.
3. K-th Smallest Element: In-order traversal yields sorted elements.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(H) average (O(log N) for balanced BST), O(N) worst case.
 * - Space Complexity: O(H) stack space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Validate Binary Search Tree (LC 98).
- Kth Smallest Element in a BST (LC 230).
- Delete Node in a BST (LC 450).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Validate BST.
 */

#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBSTHelper(TreeNode* node, long long minVal, long long maxVal) {
    if (!node) return true;
    if (node->val <= minVal || node->val >= maxVal) return false;
    return isValidBSTHelper(node->left, minVal, node->val) &&
           isValidBSTHelper(node->right, node->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << "Is Valid BST: " << (isValidBST(root) ? "Yes" : "No") << "\n";
    return 0;
}
