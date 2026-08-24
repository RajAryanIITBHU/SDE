// Link: https://leetcode.com/problems/merge-k-sorted-lists/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Custom comparator for min-heap
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

// ==========================================
// 1. OPTIMAL APPROACH (Min-Heap / Priority Queue)
// ==========================================
// Time Complexity  : O(N log k), where N is total nodes, k is number of linked lists
// Space Complexity : O(k) for priority queue
/*
PSEUDOCODE:
1. Initialize min-heap pq of ListNodes.
2. Push head of each non-empty list into pq.
3. Create dummy node, curr = dummy.
4. While !pq.empty():
     topNode = pq.top(), pq.pop()
     curr->next = topNode
     curr = curr->next
     if topNode->next != nullptr:
         pq.push(topNode->next)
5. Return dummy->next.
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            curr->next = node;
            curr = curr->next;

            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};
