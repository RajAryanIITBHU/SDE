// Link: https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Recursion / Backtracking Carry Addition)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n) recursion stack
/*
PSEUDOCODE:
1. Helper addCarry(node):
     if node == nullptr return 1
     carry = addCarry(node->next)
     sum = node->data + carry
     node->data = sum % 10
     return sum / 10
2. carry = addCarry(head).
3. If carry > 0:
     newNode = new Node(carry)
     newNode->next = head
     return newNode
4. Return head.
*/

class Solution {
private:
    int addCarry(Node* node) {
        if (node == nullptr) {
            return 1; // Base addition of 1 at the least significant digit
        }

        int carry = addCarry(node->next);
        int sum = node->data + carry;
        node->data = sum % 10;
        return sum / 10;
    }

public:
    Node* addOne(Node* head) {
        int carry = addCarry(head);

        if (carry > 0) {
            Node* newHead = new Node(carry);
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};
