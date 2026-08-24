// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
// 1. OPTIMAL APPROACH (Dummy Node + Complete Duplicate Elimination)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Create dummy node pointing to head: dummy = new ListNode(0, head).
2. prev = dummy.
3. While head != nullptr:
     if head->next != nullptr && head->val == head->next->val:
         While head->next != nullptr && head->val == head->next->val:
             head = head->next
         prev->next = head->next // Bypass all duplicate nodes
     else:
         prev = prev->next
     head = head->next
4. Return dummy->next.
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (head != nullptr) {
            // Check if head is start of a duplicate sequence
            if (head->next != nullptr && head->val == head->next->val) {
                // Skip all nodes with this value
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next; // Exclude all duplicates
            } else {
                prev = prev->next;
            }
            head = head->next;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
