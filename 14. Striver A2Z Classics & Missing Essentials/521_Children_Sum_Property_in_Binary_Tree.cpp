// Link: https://www.geeksforgeeks.org/problems/children-sum-parent/1

#include <iostream>

using namespace std;

// Definition for binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Check Children Sum Property)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h)
/*
PSEUDOCODE:
1. If root is null or leaf node -> return 1.
2. sum = 0.
3. If root->left: sum += root->left->data.
4. If root->right: sum += root->right->data.
5. If root->data == sum && isSumProperty(root->left) && isSumProperty(root->right):
     return 1
6. Return 0.
*/

class Solution {
public:
    int isSumProperty(Node *root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return 1;
        }

        int sum = 0;
        if (root->left != nullptr) sum += root->left->data;
        if (root->right != nullptr) sum += root->right->data;

        if (root->data == sum && isSumProperty(root->left) && isSumProperty(root->right)) {
            return 1;
        }

        return 0;
    }
};
