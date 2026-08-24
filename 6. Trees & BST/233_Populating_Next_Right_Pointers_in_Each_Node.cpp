// Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

#include <iostream>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Level-by-Level In-Place Pointers)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If root == nullptr return nullptr.
2. leftmost = root.
3. While leftmost->left != nullptr:
     head = leftmost
     While head != nullptr:
         head->left->next = head->right
         if head->next != nullptr:
             head->right->next = head->next->left
         head = head->next
     leftmost = leftmost->left
4. Return root.
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;

        Node* leftmost = root;

        // Traverse level by level using already established 'next' pointers
        while (leftmost->left != nullptr) {
            Node* head = leftmost;

            while (head != nullptr) {
                // Connection 1: children of same parent
                head->left->next = head->right;

                // Connection 2: right child to left child of next node
                if (head->next != nullptr) {
                    head->right->next = head->next->left;
                }

                head = head->next;
            }

            leftmost = leftmost->left;
        }

        return root;
    }
};
