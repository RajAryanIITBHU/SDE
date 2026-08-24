// Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/

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
// 1. OPTIMAL APPROACH (In-Place Node Modification)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) in-place modification
/*
PSEUDOCODE:
1. modify = head->next, nextSumNode = head->next.
2. While nextSumNode != nullptr:
     sum = 0
     While nextSumNode->val != 0:
         sum += nextSumNode->val
         nextSumNode = nextSumNode->next
     modify->val = sum
     nextSumNode = nextSumNode->next
     modify->next = nextSumNode
     modify = modify->next
3. Return head->next.
*/

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* modify = head->next;
        ListNode* curr = head->next;

        while (curr != nullptr) {
            int sum = 0;

            // Sum all values until next zero
            while (curr != nullptr && curr->val != 0) {
                sum += curr->val;
                curr = curr->next;
            }

            modify->val = sum; // Overwrite node with sum
            curr = curr->next; // Move past the zero
            modify->next = (curr != nullptr) ? modify->next : nullptr;
            modify = modify->next;
        }

        return head->next;
    }
};
