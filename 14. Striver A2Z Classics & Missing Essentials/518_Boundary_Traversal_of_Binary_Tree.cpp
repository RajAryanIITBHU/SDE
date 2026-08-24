// Link: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

#include <iostream>
#include <vector>

using namespace std;

// Definition for binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Left Boundary + Leaf Nodes + Reversed Right Boundary)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h)
/*
PSEUDOCODE:
1. Helper isLeaf(node): return !node->left && !node->right.
2. Helper addLeftBoundary(root, res):
     curr = root->left
     While curr:
         if !isLeaf(curr) res.push_back(curr->data)
         curr = curr->left ? curr->left : curr->right
3. Helper addLeaves(root, res):
     if isLeaf(root): res.push_back(root->data); return
     if root->left: addLeaves(root->left, res)
     if root->right: addLeaves(root->right, res)
4. Helper addRightBoundary(root, res):
     curr = root->right, stack / temp vector
     While curr:
         if !isLeaf(curr) temp.push_back(curr->data)
         curr = curr->right ? curr->right : curr->left
     Add temp in reverse order to res.
5. If root == nullptr return {}.
6. If !isLeaf(root) res.push_back(root->data).
7. addLeftBoundary, addLeaves, addRightBoundary.
8. Return res.
*/

class Solution {
private:
    bool isLeaf(Node* node) {
        return node->left == nullptr && node->right == nullptr;
    }

    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr != nullptr) {
            if (!isLeaf(curr)) {
                res.push_back(curr->data);
            }
            if (curr->left != nullptr) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }

    void addLeaves(Node* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left != nullptr) addLeaves(root->left, res);
        if (root->right != nullptr) addLeaves(root->right, res);
    }

    void addRightBoundary(Node* root, vector<int>& res) {
        Node* curr = root->right;
        vector<int> temp;

        while (curr != nullptr) {
            if (!isLeaf(curr)) {
                temp.push_back(curr->data);
            }
            if (curr->right != nullptr) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        for (int i = (int)temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }

public:
    vector<int> boundaryTraversal(Node *root) {
        if (root == nullptr) return {};

        vector<int> res;
        if (!isLeaf(root)) {
            res.push_back(root->data);
        }

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};
