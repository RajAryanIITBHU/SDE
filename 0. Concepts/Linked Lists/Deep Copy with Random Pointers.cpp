/*
 * ============================================================================
 * Concept: Copy List with Random Pointer
 * Subtopic: Linked Lists
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Deep copies a linked list where each node contains an extra `random` pointer.
Two approaches:
1. Hash Map Approach: Map `original_node -> new_node`.
2. In-place Interleaving Approach: Insert cloned nodes directly after original nodes `A -> A' -> B -> B'`, set random pointers `A'->random = A->random->next`, then separate the two lists.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time complexity.
 * - Space Complexity: O(1) auxiliary space for in-place approach, O(N) for Hash Map approach.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Copy List with Random Pointer (LC 138).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. In-place interleave & split.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

// In-place O(1) space copy
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    // 1. Interleave cloned nodes
    Node* curr = head;
    while (curr) {
        Node* clone = new Node(curr->val);
        clone->next = curr->next;
        curr->next = clone;
        curr = clone->next;
    }

    // 2. Assign random pointers
    curr = head;
    while (curr) {
        if (curr->random) curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    // 3. Separate lists
    curr = head;
    Node* dummy = new Node(0);
    Node* copyCurr = dummy;
    while (curr) {
        copyCurr->next = curr->next;
        copyCurr = copyCurr->next;
        curr->next = curr->next->next;
        curr = curr->next;
    }

    Node* res = dummy->next;
    delete dummy;
    return res;
}

int main() {
    Node* n1 = new Node(7);
    n1->next = new Node(13);
    Node* copied = copyRandomList(n1);
    cout << "Copied Val: " << copied->val << "\n";
    return 0;
}
