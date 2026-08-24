// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
// 1. OPTIMAL APPROACH (Fast & Slow Pointers with Dummy Node)
// ==========================================
// Time Complexity  : O(L) single pass, where L is length of list
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Create dummy node pointing to head: dummy->next = head.
2. Initialize fast = dummy, slow = dummy.
3. Advance fast pointer n + 1 steps forward.
4. While fast != nullptr:
     fast = fast->next
     slow = slow->next
5. slow is now right before the target node to delete!
6. slow->next = slow->next->next
7. Return dummy->next.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n + 1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the nth node from the end
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
