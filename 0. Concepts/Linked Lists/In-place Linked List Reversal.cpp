/*
 * ============================================================================
 * Concept: In-place Linked List Reversal
 * Subtopic: Linked Lists
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Reverses pointers in a linked list using `prev`, `curr`, and `next` pointers.
Can reverse entire list, a subsegment `[left, right]`, or nodes in `K`-groups.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time complexity.
 * - Space Complexity: O(1) auxiliary space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Reverse Linked List (LC 206).
- Reverse Linked List II (LC 92).
- Reverse Nodes in k-Group (LC 25).
- Palindrome Linked List (Reverse second half).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Reverse Full List (LC 206).
2. Reverse Nodes in K-Group (LC 25).
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head = reverseList(head);
    cout << "Reversed Head Val: " << head->val << "\n";
    return 0;
}
