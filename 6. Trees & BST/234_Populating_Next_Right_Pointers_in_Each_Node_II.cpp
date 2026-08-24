// Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

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
// 1. OPTIMAL APPROACH (Dummy Head for Next Level)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. curr = root.
2. While curr != nullptr:
     dummyHead = new Node(0), tail = dummyHead
     While curr != nullptr:
         if curr->left != nullptr:
             tail->next = curr->left
             tail = tail->next
         if curr->right != nullptr:
             tail->next = curr->right
             tail = tail->next
         curr = curr->next
     curr = dummyHead->next // Move to start of next level
3. Return root.
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* curr = root;

        while (curr != nullptr) {
            Node dummy(0);
            Node* tail = &dummy;

            // Traverse current level and stitch next level
            while (curr != nullptr) {
                if (curr->left != nullptr) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right != nullptr) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next;
            }

            // Move to first node of next level
            curr = dummy.next;
        }

        return root;
    }
};
