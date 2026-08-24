// Link: https://leetcode.com/problems/rotate-list/

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
// 1. OPTIMAL APPROACH (Make Ring + Break at New Tail)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If head == nullptr || head->next == nullptr || k == 0 return head.
2. Compute length len and reach tail node.
3. k = k % len. If k == 0 return head.
4. Connect tail to head to form circular list: tail->next = head.
5. Steps to new tail = len - k.
6. Traverse steps to reach new tail:
     newTail = head
     For i from 1 to len - k - 1: newTail = newTail->next
7. newHead = newTail->next
8. newTail->next = nullptr (break circular link)
9. Return newHead.
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) return head;

        // Step 1: Calculate length and find tail
        int len = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }

        k = k % len;
        if (k == 0) return head;

        // Step 2: Form a circular linked list
        tail->next = head;

        // Step 3: Find new tail (len - k steps from head)
        ListNode* newTail = head;
        for (int i = 1; i < len - k; i++) {
            newTail = newTail->next;
        }

        // Step 4: Break circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
