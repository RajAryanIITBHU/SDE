// Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
// 1. OPTIMAL APPROACH (Fast & Slow Pointers with Prev Pointer)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If head == nullptr || head->next == nullptr return nullptr.
2. slow = head, fast = head, prev = nullptr.
3. While fast != nullptr && fast->next != nullptr:
     prev = slow
     slow = slow->next
     fast = fast->next->next
4. Delete slow node: prev->next = slow->next, delete slow.
5. Return head.
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete middle node
        prev->next = slow->next;
        delete slow;

        return head;
    }
};
