// Link: https://leetcode.com/problems/split-linked-list-in-parts/

#include <iostream>
#include <vector>

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
// 1. OPTIMAL APPROACH (Length Calculation + Pointer Slicing)
// ==========================================
// Time Complexity  : O(n + k)
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. Count total nodes in list: len.
2. Base part size = len / k, extra nodes = len % k.
3. Initialize ans vector of size k with nullptr.
4. curr = head, prev = nullptr.
5. For i from 0 to k-1:
     ans[i] = curr
     partSize = baseSize + (i < extra ? 1 : 0)
     For j from 0 to partSize - 1:
         prev = curr
         if curr != nullptr -> curr = curr->next
     if prev != nullptr -> prev->next = nullptr // Sever connection
6. Return ans.
*/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }

        int baseSize = len / k;
        int extra = len % k; // First 'extra' parts get 1 additional node

        vector<ListNode*> ans(k, nullptr);
        curr = head;
        ListNode* prev = nullptr;

        for (int i = 0; i < k && curr != nullptr; i++) {
            ans[i] = curr;
            int partSize = baseSize + (i < extra ? 1 : 0);

            for (int j = 0; j < partSize; j++) {
                prev = curr;
                curr = curr->next;
            }

            if (prev != nullptr) {
                prev->next = nullptr; // Cut off the part
            }
        }

        return ans;
    }
};
