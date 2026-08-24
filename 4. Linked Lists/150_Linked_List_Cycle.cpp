// Link: https://leetcode.com/problems/linked-list-cycle/

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Floyd's Tortoise and Hare)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize slow = head, fast = head.
2. While fast != nullptr && fast->next != nullptr:
     slow = slow->next
     fast = fast->next->next
     if slow == fast -> return true (cycle detected!)
3. Return false.
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            // Fast meets slow -> cycle exists
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};
