/*
 * ============================================================================
 * Concept: Reorder / Interleave Linked List
 * Subtopic: Linked Lists
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Reorders linked list `L0 -> L1 -> ... -> Ln-1 -> Ln` into `L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2...`.
Steps:
1. Find middle using Fast & Slow pointers.
2. Reverse second half of list.
3. Interleave (zip) first half and reversed second half.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time complexity.
 * - Space Complexity: O(1) auxiliary space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Reorder List (LC 143).
- Odd Even Linked List (LC 328).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Reorder List (LC 143).
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void reorderList(ListNode* head) {
    if (!head || !head->next) return;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Reverse second half
    ListNode *prev = nullptr, *curr = slow->next;
    slow->next = nullptr;
    while (curr) {
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    // Interleave
    ListNode *first = head, *second = prev;
    while (second) {
        ListNode *t1 = first->next, *t2 = second->next;
        first->next = second;
        second->next = t1;
        first = t1;
        second = t2;
    }
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    reorderList(head);
    cout << "First -> Next: " << head->next->val << "\n"; // 4
    return 0;
}
