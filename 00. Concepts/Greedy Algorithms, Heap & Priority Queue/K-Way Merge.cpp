/*
 * ============================================================================
 * Concept: K-Way Merge
 * Subtopic: Greedy Algorithms, Heap & Priority Queue
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Merges K sorted lists or arrays into a single sorted output sequence using a Min-Heap.
Heap stores tuple `{val, list_index, element_index}`.
Pop smallest element, insert into output, then push next element from the same list into heap.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N log K) where N is total elements, K is number of lists.
 * - Space Complexity: O(K) heap space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Merge K Sorted Lists (LC 23).
- Smallest Range Covering Elements from K Lists (LC 632).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Merge K Sorted Lists (LC 23).
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto comp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

    for (ListNode* l : lists) {
        if (l) pq.push(l);
    }

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (!pq.empty()) {
        ListNode* node = pq.top(); pq.pop();
        tail->next = node;
        tail = tail->next;
        if (node->next) pq.push(node->next);
    }
    return dummy.next;
}

int main() {
    ListNode* l1 = new ListNode(1); l1->next = new ListNode(4);
    ListNode* l2 = new ListNode(2); l2->next = new ListNode(5);
    vector<ListNode*> lists = {l1, l2};
    ListNode* merged = mergeKLists(lists);
    cout << "Merged Head: " << merged->val << "\n"; // 1
    return 0;
}
