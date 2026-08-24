/*
 * ============================================================================
 * Concept: Construct Binary Tree from Traversals
 * Subtopic: Trees & BST
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Reconstructs a binary tree from traversal arrays:
1. Preorder + Inorder (LC 105): First element of preorder is root. Locate root in inorder array using a hash map to determine left and right subtree sizes.
2. Postorder + Inorder (LC 106): Last element of postorder is root.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time using hash map for O(1) inorder index lookup.
 * - Space Complexity: O(N) space for hash map and recursion stack.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Construct Binary Tree from Preorder and Inorder Traversal (LC 105).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Preorder + Inorder Tree Construction.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildHelper(const vector<int>& preorder, int pStart, int pEnd,
                      int iStart, int iEnd, unordered_map<int, int>& inMap) {
    if (pStart > pEnd || iStart > iEnd) return nullptr;

    int rootVal = preorder[pStart];
    TreeNode* root = new TreeNode(rootVal);
    int inIndex = inMap[rootVal];
    int leftSize = inIndex - iStart;

    root->left = buildHelper(preorder, pStart + 1, pStart + leftSize, iStart, inIndex - 1, inMap);
    root->right = buildHelper(preorder, pStart + leftSize + 1, pEnd, inIndex + 1, iEnd, inMap);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < (int)inorder.size(); ++i) inMap[inorder[i]] = i;
    return buildHelper(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inMap);
}

int main() {
    vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> in = {9, 3, 15, 20, 7};
    TreeNode* root = buildTree(pre, in);
    cout << "Reconstructed Root Val: " << root->val << "\n";
    return 0;
}
