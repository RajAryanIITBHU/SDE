// Link: https://www.geeksforgeeks.org/problems/largest-bst/1

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

// Definition for binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Postorder Subtree Validation)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h)
/*
PSEUDOCODE:
Each subtree returns: {isBST, size, minVal, maxVal}.
1. If node is null -> return {true, 0, INT_MAX, INT_MIN}.
2. Postorder traversal of left and right subtrees.
3. If left.isBST && right.isBST && left.maxVal < node->data && node->data < right.minVal:
     return {true, 1 + left.size + right.size, min(node->data, left.minVal), max(node->data, right.maxVal)}
4. Else:
     return {false, max(left.size, right.size), 0, 0}
5. Return largestBST(root).size.
*/

class Solution {
private:
    struct SubtreeInfo {
        bool isBST;
        int size;
        int minVal;
        int maxVal;
    };

    SubtreeInfo postorder(Node* root) {
        if (root == nullptr) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        SubtreeInfo left = postorder(root->left);
        SubtreeInfo right = postorder(root->right);

        if (left.isBST && right.isBST && left.maxVal < root->data && root->data < right.minVal) {
            int currentSize = 1 + left.size + right.size;
            int currentMin = min(root->data, left.minVal);
            int currentMax = max(root->data, right.maxVal);
            return {true, currentSize, currentMin, currentMax};
        }

        return {false, max(left.size, right.size), 0, 0};
    }

public:
    int largestBst(Node *root) {
        return postorder(root).size;
    }
};
