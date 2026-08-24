// Link: https://leetcode.com/problems/remove-linked-list-elements/

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
// 1. OPTIMAL APPROACH (Dummy Node Traversal)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Create dummy node pointing to head: dummy = new ListNode(0, head).
2. curr = dummy.
3. While curr->next != nullptr:
     if curr->next->val == val:
         temp = curr->next
         curr->next = curr->next->next
         delete temp
     else:
         curr = curr->next
4. Return dummy->next.
*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;

        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                ListNode* nodeToDelete = curr->next;
                curr->next = curr->next->next;
                delete nodeToDelete;
            } else {
                curr = curr->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
