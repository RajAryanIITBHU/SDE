// Link: https://leetcode.com/problems/merge-in-between-linked-lists/

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
// 1. OPTIMAL APPROACH (Pointer Relinking)
// ==========================================
// Time Complexity  : O(n + m)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Traverse list1 to find node before index a: nodeA_prev.
2. Traverse further to find node at index b: nodeB.
3. Find tail of list2: tail2.
4. nodeA_prev->next = list2
5. tail2->next = nodeB->next
6. Return list1.
*/

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* nodeA_prev = list1;
        for (int i = 0; i < a - 1; i++) {
            nodeA_prev = nodeA_prev->next;
        }

        ListNode* nodeB = nodeA_prev;
        for (int i = 0; i < b - a + 1; i++) {
            nodeB = nodeB->next;
        }

        // Find the tail of list2
        ListNode* tail2 = list2;
        while (tail2->next != nullptr) {
            tail2 = tail2->next;
        }

        // Connect node before 'a' to head of list2
        nodeA_prev->next = list2;

        // Connect tail of list2 to node after 'b'
        tail2->next = nodeB->next;

        return list1;
    }
};
