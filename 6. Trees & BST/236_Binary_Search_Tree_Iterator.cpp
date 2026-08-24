// Link: https://leetcode.com/problems/binary-search-tree-iterator/

#include <iostream>
#include <stack>

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
// 1. OPTIMAL APPROACH (Controlled Stack for Inorder Traversal)
// ==========================================
// Time Complexity  : next: Amortized O(1), hasNext: O(1)
// Space Complexity : O(h), where h is tree height
/*
PSEUDOCODE:
1. Maintain stack<TreeNode*> st.
2. Helper pushAllLeft(node):
     While node != nullptr:
         st.push(node)
         node = node->left
3. BSTIterator(root): pushAllLeft(root).
4. next():
     topNode = st.top(), st.pop()
     pushAllLeft(topNode->right)
     return topNode->val
5. hasNext(): return !st.empty().
*/

class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }

    int next() {
        TreeNode* topNode = st.top();
        st.pop();

        pushAllLeft(topNode->right);

        return topNode->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};
