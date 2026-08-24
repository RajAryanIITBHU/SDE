// Link: https://leetcode.com/problems/same-tree/

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
// 1. OPTIMAL APPROACH (Recursive DFS)
// ==========================================
// Time Complexity  : O(min(n, m))
// Space Complexity : O(h)
/*
PSEUDOCODE:
1. If p == nullptr && q == nullptr return true.
2. If p == nullptr || q == nullptr return false.
3. If p->val != q->val return false.
4. Return isSameTree(p->left, q->left) && isSameTree(p->right, q->right).
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
