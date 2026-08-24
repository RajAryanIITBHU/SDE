// Link: https://leetcode.com/problems/reverse-linked-list-ii/

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Iterative In-place Reversal)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Create dummy node pointing to head: dummy = new ListNode(0, head).
2. prev = dummy.
3. Advance prev left - 1 times to reach node just before reversal subsegment.
4. curr = prev->next.
5. For i from 0 to right - left - 1:
     temp = curr->next
     curr->next = temp->next
     temp->next = prev->next
     prev->next = temp
6. Return dummy->next.
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        // Reach node right before 'left' position
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        // In-place subsegment reversal
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
