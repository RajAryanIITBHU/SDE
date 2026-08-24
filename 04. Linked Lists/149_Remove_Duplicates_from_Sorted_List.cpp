// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
// 1. OPTIMAL APPROACH (Single Pass Iteration)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If head == nullptr return nullptr.
2. curr = head.
3. While curr != nullptr && curr->next != nullptr:
     if curr->val == curr->next->val:
         temp = curr->next
         curr->next = curr->next->next
         delete temp
     else:
         curr = curr->next
4. Return head.
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                ListNode* duplicate = curr->next;
                curr->next = curr->next->next;
                delete duplicate;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
