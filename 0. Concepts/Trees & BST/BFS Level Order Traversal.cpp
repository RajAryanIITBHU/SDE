/*
 * ============================================================================
 * Concept: BFS Level Order Traversal
 * Subtopic: Trees & BST
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Traverses tree level by level using a FIFO Queue (`std::queue`).
At each level, record `queue.size()`, pop all nodes of current level, and push their children.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time complexity.
 * - Space Complexity: O(W) queue space where W is max width of tree.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Binary Tree Level Order Traversal (LC 102).
- Zigzag Level Order Traversal (LC 103).
- Right / Left Side View of Binary Tree (LC 199).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Level Order Traversal.
2. Zigzag Level Order Traversal.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        vector<int> current_level;
        for (int i = 0; i < sz; ++i) {
            TreeNode* node = q.front(); q.pop();
            current_level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(current_level);
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    auto res = levelOrder(root);
    cout << "Level 0 Size: " << res[0].size() << "\n";
    return 0;
}
