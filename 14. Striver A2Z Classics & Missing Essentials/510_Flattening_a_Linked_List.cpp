// Link: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include <iostream>

using namespace std;

// Definition for 2D Linked List (next and bottom pointers).
struct Node {
    int data;
    Node* next;
    Node* bottom;
    Node(int val) : data(val), next(nullptr), bottom(nullptr) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Recursive 2-Way Merging of Bottom Lists)
// ==========================================
// Time Complexity  : O(N * M), where N is next nodes and M is avg bottom nodes
// Space Complexity : O(N) recursion stack
/*
PSEUDOCODE:
1. Helper merge2Lists(a, b):
     dummy = new Node(0), curr = dummy
     While a && b:
         if a->data <= b->data:
             curr->bottom = a, a = a->bottom
         else:
             curr->bottom = b, b = b->bottom
         curr = curr->bottom
     curr->bottom = a ? a : b
     return dummy->bottom
2. flatten(root):
     if root == nullptr || root->next == nullptr return root
     root->next = flatten(root->next)
     root = merge2Lists(root, root->next)
     return root
*/

class Solution {
private:
    Node* merge2Lists(Node* a, Node* b) {
        Node* dummy = new Node(0);
        Node* curr = dummy;

        while (a != nullptr && b != nullptr) {
            if (a->data <= b->data) {
                curr->bottom = a;
                a = a->bottom;
            } else {
                curr->bottom = b;
                b = b->bottom;
            }
            curr = curr->bottom;
        }

        if (a != nullptr) curr->bottom = a;
        else curr->bottom = b;

        return dummy->bottom;
    }

public:
    Node* flatten(Node* root) {
        if (root == nullptr || root->next == nullptr) {
            return root;
        }

        // Recursively flatten right lists
        root->next = flatten(root->next);

        // Merge current bottom list with flattened right list
        root = merge2Lists(root, root->next);

        return root;
    }
};
