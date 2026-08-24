// Link: https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Three Dummy Buckets 0, 1, 2 Linking)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize three dummy heads: zeroHead(0), oneHead(0), twoHead(0).
2. Distribute nodes into the 3 buckets.
3. Connect 0's list to 1's list (or 2's if 1 is empty).
4. Connect 1's list to 2's list.
5. Terminate 2's tail with nullptr.
6. Return zeroHead.next.
*/

class Solution {
public:
    Node* segregate(Node *head) {
        Node* zeroHead = new Node(0);
        Node* oneHead = new Node(0);
        Node* twoHead = new Node(0);

        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;

        Node* curr = head;

        while (curr != nullptr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        // Link the 3 partitions together
        zero->next = (oneHead->next != nullptr) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = nullptr;

        Node* newHead = zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return newHead;
    }
};
