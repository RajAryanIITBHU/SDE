// Link: https://leetcode.com/problems/check-completeness-of-a-binary-tree/

#include <iostream>
#include <queue>

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
// 1. OPTIMAL APPROACH (BFS Queue with Null Flag)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize queue<TreeNode*> q, push root, seenNull = false.
2. While !q.empty():
     node = q.front(), q.pop()
     if node == nullptr:
         seenNull = true
     else:
         if seenNull return false // Non-null node found after a null node in level order
         q.push(node->left)
         q.push(node->right)
3. Return true.
*/

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool seenNull = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                seenNull = true;
            } else {
                if (seenNull) {
                    return false; // Found a valid node after seeing a null
                }

                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};
