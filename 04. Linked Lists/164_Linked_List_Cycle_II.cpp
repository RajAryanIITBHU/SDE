// Link: https://leetcode.com/problems/linked-list-cycle-ii/

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Floyd's Cycle Detection + Entry Point)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize slow = head, fast = head, hasCycle = false.
2. While fast != nullptr && fast->next != nullptr:
     slow = slow->next
     fast = fast->next->next
     if slow == fast:
         hasCycle = true
         break
3. If !hasCycle return nullptr.
4. Reset entry = head.
5. While entry != slow:
     entry = entry->next
     slow = slow->next
6. Return entry (cycle starting node).
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool hasCycle = false;

        // Step 1: Detect if a cycle exists
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        if (!hasCycle) return nullptr;

        // Step 2: Find cycle start node
        ListNode* entry = head;
        while (entry != slow) {
            entry = entry->next;
            slow = slow->next;
        }

        return entry;
    }
};
