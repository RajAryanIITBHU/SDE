// Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

#include <iostream>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

// ==========================================
// 1. OPTIMAL APPROACH (Iterative Splice)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. curr = head.
2. While curr != nullptr:
     if curr->child != nullptr:
         Find tail of child list: childTail = curr->child
         While childTail->next != nullptr: childTail = childTail->next
         
         // Splice child list into main list
         childTail->next = curr->next
         if curr->next != nullptr -> curr->next->prev = childTail
         
         curr->next = curr->child
         curr->child->prev = curr
         curr->child = nullptr
     curr = curr->next
3. Return head.
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->child != nullptr) {
                // Find tail of the child branch
                Node* childTail = curr->child;
                while (childTail->next != nullptr) {
                    childTail = childTail->next;
                }

                // Connect childTail to curr->next
                childTail->next = curr->next;
                if (curr->next != nullptr) {
                    curr->next->prev = childTail;
                }

                // Connect curr to curr->child
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }

            curr = curr->next;
        }

        return head;
    }
};
