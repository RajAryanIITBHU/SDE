// Link: https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

#include <iostream>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

// ==========================================
// 1. OPTIMAL APPROACH (Inorder Traversal Pointer Relinking)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h) recursion stack
/*
PSEUDOCODE:
1. Maintain firstNode = nullptr, prevNode = nullptr.
2. Helper inorder(node):
     if node == nullptr return
     inorder(node->left)
     if prevNode != nullptr:
         prevNode->right = node
         node->left = prevNode
     else:
         firstNode = node
     prevNode = node
     inorder(node->right)
3. If root == nullptr return nullptr.
4. inorder(root)
5. prevNode->right = firstNode, firstNode->left = prevNode (make circular).
6. Return firstNode.
*/

class Solution {
private:
    Node* firstNode = nullptr;
    Node* prevNode = nullptr;

    void inorder(Node* node) {
        if (node == nullptr) return;

        inorder(node->left);

        if (prevNode != nullptr) {
            prevNode->right = node;
            node->left = prevNode;
        } else {
            firstNode = node; // Smallest element is head of DLL
        }
        prevNode = node;

        inorder(node->right);
    }

public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;

        inorder(root);

        // Connect head and tail to form circular DLL
        prevNode->right = firstNode;
        firstNode->left = prevNode;

        return firstNode;
    }
};
