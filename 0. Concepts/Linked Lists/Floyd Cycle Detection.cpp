/*
 * ============================================================================
 * Concept: Floyd's Fast & Slow Pointer Cycle Detection
 * Subtopic: Linked Lists
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Uses two pointers (`slow` moving 1 step, `fast` moving 2 steps) to detect cycles in linked lists.
If a cycle exists, `fast` and `slow` will meet.
To find cycle entrance (LC 142): Reset `slow` to `head`, keep `fast` at intersection, move both 1 step at a time until they meet.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time complexity.
 * - Space Complexity: O(1) auxiliary space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Linked List Cycle Detection (LC 141).
- Find Cycle Entrance Node (LC 142).
- Middle of Linked List (LC 876).
- Find the Duplicate Number (LC 287 - Array treated as implicit linked list).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Linked List Cycle I (LC 141).
2. Linked List Cycle II (LC 142).
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = head; // cycle
    cout << "Has Cycle: " << (hasCycle(head) ? "Yes" : "No") << "\n";
    return 0;
}
