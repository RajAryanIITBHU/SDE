/*
 * ============================================================================
 * Concept: Linked List Merge Sort
 * Subtopic: Linked Lists
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Sorts a linked list in O(N log N) time and O(log N) stack space using divide-and-conquer.
Uses Fast & Slow pointers to split list in half, recursively sorts both halves, and merges them using Merge Two Sorted Lists logic.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N log N) time complexity.
 * - Space Complexity: O(log N) recursion stack space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Sort List (LC 148).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Merge Sort on Linked List.
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) { tail->next = l1; l1 = l1->next; }
        else { tail->next = l2; l2 = l2->next; }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow->next;
    slow->next = nullptr;
    return merge(sortList(head), sortList(mid));
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head = sortList(head);
    cout << "Sorted Head: " << head->val << "\n";
    return 0;
}
