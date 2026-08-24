// Link: https://leetcode.com/problems/swap-nodes-in-pairs/

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
// 1. OPTIMAL APPROACH (Iterative Pointer Manipulation)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Create dummy node pointing to head: dummy = new ListNode(0, head).
2. prev = dummy.
3. While prev->next != nullptr && prev->next->next != nullptr:
     first = prev->next
     second = prev->next->next
     
     // Rewire pointers
     first->next = second->next
     second->next = first
     prev->next = second
     
     prev = first
4. Return dummy->next.
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Swap nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Advance prev to start of next pair
            prev = first;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
