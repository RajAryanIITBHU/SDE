// Link: https://leetcode.com/problems/partition-list/

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
// 1. OPTIMAL APPROACH (Two Separate Chains)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Create lessHead and greaterHead dummy nodes.
2. less = lessHead, greater = greaterHead.
3. While head != nullptr:
     if head->val < x:
         less->next = head
         less = less->next
     else:
         greater->next = head
         greater = greater->next
     head = head->next
4. greater->next = nullptr (prevent cycle)
5. less->next = greaterHead->next (connect both chains)
6. Return lessHead->next.
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);

        ListNode* less = lessHead;
        ListNode* greater = greaterHead;

        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        greater->next = nullptr;
        less->next = greaterHead->next;

        ListNode* newHead = lessHead->next;
        delete lessHead;
        delete greaterHead;
        return newHead;
    }
};
