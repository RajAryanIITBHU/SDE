// Link: https://leetcode.com/problems/add-two-numbers/

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
// 1. OPTIMAL APPROACH (Dummy Head + Carry Propagation)
// ==========================================
// Time Complexity  : O(max(n, m))
// Space Complexity : O(max(n, m)) for the output list
/*
PSEUDOCODE:
1. Create dummyHead node, curr = dummyHead, carry = 0.
2. While l1 != nullptr || l2 != nullptr || carry != 0:
     sum = carry
     if l1 != nullptr: sum += l1->val, l1 = l1->next
     if l2 != nullptr: sum += l2->val, l2 = l2->next
     carry = sum / 10
     curr->next = new ListNode(sum % 10)
     curr = curr->next
3. Return dummyHead->next.
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy->next;
    }
};
