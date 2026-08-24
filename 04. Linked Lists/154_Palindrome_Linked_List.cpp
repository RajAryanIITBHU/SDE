// Link: https://leetcode.com/problems/palindrome-linked-list/

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
// 1. OPTIMAL APPROACH (Find Middle + Reverse Second Half + Compare)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Find middle of list using fast and slow pointers.
2. Reverse the second half of the list starting from slow.
3. Compare first half (head) with second half (reversedHead).
4. (Optional) Restore the original list structure.
5. Return true if all matched, else false.
*/

class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        // Step 1: Find middle node
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalf = reverse(slow->next);

        // Step 3: Compare both halves
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;
        bool palindrome = true;

        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                palindrome = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // Step 4: Restore list structure
        slow->next = reverse(secondHalf);

        return palindrome;
    }
};
