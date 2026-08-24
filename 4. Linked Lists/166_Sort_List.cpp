// Link: https://leetcode.com/problems/sort-list/

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
// 1. OPTIMAL APPROACH (Merge Sort on Linked List)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(log n) recursion call stack
/*
PSEUDOCODE:
1. Base case: if head == nullptr || head->next == nullptr return head.
2. Find middle of list using fast & slow pointers.
3. Split list into two halves: left = head, right = mid->next, mid->next = nullptr.
4. Recursively sort both halves: sortedLeft = sortList(left), sortedRight = sortList(right).
5. Merge two sorted lists and return.
*/

class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        curr->next = (l1 != nullptr) ? l1 : l2;

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        // Step 1: Find middle using fast and slow pointers
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr; // Split into two lists: head..prev and slow..end

        // Step 2: Recursively sort halves
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        // Step 3: Merge sorted halves
        return mergeTwoLists(l1, l2);
    }
};
