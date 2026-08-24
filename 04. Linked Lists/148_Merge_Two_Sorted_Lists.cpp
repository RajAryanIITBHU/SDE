// Link: https://leetcode.com/problems/merge-two-sorted-lists/

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
// 1. OPTIMAL APPROACH (Iterative Dummy Pointer)
// ==========================================
// Time Complexity  : O(n + m)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Create dummy node, curr = dummy.
2. While list1 != nullptr && list2 != nullptr:
     if list1->val <= list2->val:
         curr->next = list1
         list1 = list1->next
     else:
         curr->next = list2
         list2 = list2->next
     curr = curr->next
3. Attach remaining list:
     curr->next = (list1 != nullptr) ? list1 : list2
4. Return dummy->next.
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        // Attach whatever is remaining
        curr->next = (list1 != nullptr) ? list1 : list2;

        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};
