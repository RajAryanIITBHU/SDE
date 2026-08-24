// Link: https://leetcode.com/problems/add-two-numbers-ii/

#include <iostream>
#include <stack>

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
// 1. OPTIMAL APPROACH (Stacks + Head Insertion)
// ==========================================
// Time Complexity  : O(n + m)
// Space Complexity : O(n + m) for stacks
/*
PSEUDOCODE:
1. Push all node values of l1 into stack st1.
2. Push all node values of l2 into stack st2.
3. carry = 0, head = nullptr.
4. While !st1.empty() || !st2.empty() || carry != 0:
     sum = carry
     if !st1.empty() -> sum += st1.top(), st1.pop()
     if !st2.empty() -> sum += st2.top(), st2.pop()
     carry = sum / 10
     newNode = new ListNode(sum % 10, head) // Insert at front
     head = newNode
5. Return head.
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;

        while (l1 != nullptr) {
            st1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            st2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* head = nullptr;
        int carry = 0;

        while (!st1.empty() || !st2.empty() || carry != 0) {
            int sum = carry;

            if (!st1.empty()) {
                sum += st1.top();
                st1.pop();
            }
            if (!st2.empty()) {
                sum += st2.top();
                st2.pop();
            }

            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10, head);
            head = newNode;
        }

        return head;
    }
};
