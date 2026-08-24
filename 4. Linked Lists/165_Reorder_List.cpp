// Link: https://leetcode.com/problems/reorder-list/

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
// 1. OPTIMAL APPROACH (Find Mid + Reverse Second Half + Interleave)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Find middle of list using slow & fast pointers.
2. Reverse second half starting from slow->next.
3. Disconnect first half: slow->next = nullptr.
4. Interleave merge first half and second half:
     p1 = head, p2 = reversedHead
     While p2 != nullptr:
         t1 = p1->next, t2 = p2->next
         p1->next = p2
         p2->next = t1
         p1 = t1, p2 = t2
*/

class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalf = reverse(slow->next);
        slow->next = nullptr; // Split lists

        // Step 3: Interleave merge
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;

        while (p2 != nullptr) {
            ListNode* t1 = p1->next;
            ListNode* t2 = p2->next;

            p1->next = p2;
            p2->next = t1;

            p1 = t1;
            p2 = t2;
        }
    }
};
