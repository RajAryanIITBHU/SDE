// Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Two Pointers Head Switching)
// ==========================================
// Time Complexity  : O(n + m)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize pA = headA, pB = headB.
2. While pA != pB:
     pA = (pA == nullptr) ? headB : pA->next
     pB = (pB == nullptr) ? headA : pB->next
3. Return pA (either the intersection node or nullptr).
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode* pA = headA;
        ListNode* pB = headB;

        // Traverse both lists; switch to opposite head on reaching end
        while (pA != pB) {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }

        return pA;
    }
};
