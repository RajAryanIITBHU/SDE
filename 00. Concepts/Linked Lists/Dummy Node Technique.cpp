/*
 * ============================================================================
 * Concept: Dummy Node Guard Technique
 * Subtopic: Linked Lists
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * A `dummy` node placed before `head` simplifies edge cases when the head of the linked list might be deleted, inserted, or modified.
Returns `dummy->next` as the resulting head.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(1) extra space.
 * - Space Complexity: Eliminates special null checks for head node.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Removing N-th node from end of list (LC 19).
- Merging two sorted lists (LC 21).
- Partitioning linked list (LC 86).
- Removing duplicates from sorted list II (LC 82).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Remove Nth Node From End (LC 19).
2. Swap Nodes in Pairs (LC 24).
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode *first = dummy, *second = dummy;

    for (int i = 0; i <= n; ++i) first = first->next;

    while (first) {
        first = first->next;
        second = second->next;
    }
    ListNode* toDelete = second->next;
    second->next = second->next->next;
    delete toDelete;

    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head = removeNthFromEnd(head, 2);
    cout << "New Head Val: " << head->val << "\n";
    return 0;
}
