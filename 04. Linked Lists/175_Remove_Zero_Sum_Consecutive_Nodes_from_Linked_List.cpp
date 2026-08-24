// Link: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

#include <iostream>
#include <unordered_map>

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
// 1. OPTIMAL APPROACH (Prefix Sum + Hash Map 2-Passes)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Create dummy node pointing to head: dummy = new ListNode(0, head).
2. Create hash map mp: prefixSum -> latest_node.
3. Pass 1: Compute prefix sums and record the latest node seen with each prefix sum.
4. Pass 2: For each node, set curr->next = mp[prefixSum]->next (skips any intermediate zero-sum sublists).
5. Return dummy->next.
*/

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        unordered_map<int, ListNode*> mp; // {prefixSum, latest_node}

        // Pass 1: Record latest node for each prefix sum
        int sum = 0;
        ListNode* curr = dummy;
        while (curr != nullptr) {
            sum += curr->val;
            mp[sum] = curr;
            curr = curr->next;
        }

        // Pass 2: Connect each node to the node after its latest prefix sum match
        sum = 0;
        curr = dummy;
        while (curr != nullptr) {
            sum += curr->val;
            curr->next = mp[sum]->next;
            curr = curr->next;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
