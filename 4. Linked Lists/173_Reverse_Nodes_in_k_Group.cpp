// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/

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
// 1. OPTIMAL APPROACH (Iterative In-place K-Group Reversal)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Create dummy node pointing to head: dummy = new ListNode(0, head).
2. groupPrev = dummy.
3. While true:
     kth = getKthNode(groupPrev, k)
     if kth == nullptr -> break
     groupNext = kth->next
     
     // Reverse group: [groupPrev->next .. kth]
     prev = groupNext, curr = groupPrev->next
     While curr != groupNext:
         temp = curr->next
         curr->next = prev
         prev = curr
         curr = temp
     
     temp = groupPrev->next
     groupPrev->next = kth
     groupPrev = temp
4. Return dummy->next.
*/

class Solution {
private:
    ListNode* getKth(ListNode* curr, int k) {
        while (curr != nullptr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;

        while (true) {
            ListNode* kth = getKth(groupPrev, k);
            if (kth == nullptr) break;

            ListNode* groupNext = kth->next;

            // Reverse current k-group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
