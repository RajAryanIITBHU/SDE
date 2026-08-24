// Link: https://leetcode.com/problems/delete-nodes-and-return-forest/

#include <iostream>
#include <vector>
#include <unordered_set>

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
// 1. OPTIMAL APPROACH (Postorder DFS + Set Lookup)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Store to_delete in unordered_set st.
2. Helper processNode(root, isRoot, forest):
     if root == nullptr return nullptr
     toDelete = st.count(root->val)
     if isRoot && !toDelete -> forest.push_back(root)
     root->left = processNode(root->left, toDelete, forest)
     root->right = processNode(root->right, toDelete, forest)
     return toDelete ? nullptr : root
3. processNode(root, true, forest).
4. Return forest.
*/

class Solution {
private:
    TreeNode* processNode(TreeNode* root, bool isRoot, unordered_set<int>& toDeleteSet, vector<TreeNode*>& forest) {
        if (root == nullptr) return nullptr;

        bool deleted = toDeleteSet.find(root->val) != toDeleteSet.end();

        // If this node is a new tree root and not deleted, add to forest
        if (isRoot && !deleted) {
            forest.push_back(root);
        }

        // Its children will become roots if current node is deleted
        root->left = processNode(root->left, deleted, toDeleteSet, forest);
        root->right = processNode(root->right, deleted, toDeleteSet, forest);

        return deleted ? nullptr : root;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;

        processNode(root, true, toDeleteSet, forest);

        return forest;
    }
};
