// Link: https://www.geeksforgeeks.org/problems/find-length-of-loop/1

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Floyd's Cycle-Finding + Loop Counter)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. slow = head, fast = head.
2. While fast && fast->next:
     slow = slow->next
     fast = fast->next->next
     if slow == fast: // Cycle meeting point
         loopLength = 1, temp = slow->next
         While temp != slow:
             loopLength++
             temp = temp->next
         return loopLength
3. Return 0.
*/

class Solution {
public:
    int countNodesinLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Count the number of nodes in the cycle
                int loopLength = 1;
                Node* temp = slow->next;

                while (temp != slow) {
                    loopLength++;
                    temp = temp->next;
                }

                return loopLength;
            }
        }

        return 0;
    }
};
