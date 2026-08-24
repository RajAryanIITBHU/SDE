// Link: https://leetcode.com/problems/odd-even-linked-list/

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
// 1. OPTIMAL APPROACH (Odd and Even Pointer Partition)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If head == nullptr || head->next == nullptr return head.
2. odd = head, even = head->next, evenHead = even.
3. While even != nullptr && even->next != nullptr:
     odd->next = even->next
     odd = odd->next
     even->next = odd->next
     even = even->next
4. odd->next = evenHead (attach even list after odd list).
5. Return head.
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Save start of even list

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        // Connect end of odd list to head of even list
        odd->next = evenHead;

        return head;
    }
};
