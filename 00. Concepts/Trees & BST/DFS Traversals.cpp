/*
 * ============================================================================
 * Concept: DFS Traversals (Recursive & Iterative)
 * Subtopic: Trees & BST
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Depth-First Search traversals on binary trees:
1. Preorder (Root, Left, Right)
2. Inorder (Left, Root, Right) - yields sorted order for BST
3. Postorder (Left, Right, Root)
Iterative implementations use `std::stack`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) visits every node.
 * - Space Complexity: O(H) stack space where H is height of tree.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Tree Traversals (LC 94, 144, 145).
- BST Inorder processing.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Iterative Inorder Traversal using stack.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Iterative Inorder Traversal
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    auto res = inorderTraversal(root);
    cout << "Inorder: ";
    for (int x : res) cout << x << " ";
    cout << "\n";
    return 0;
}
