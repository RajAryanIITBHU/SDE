// Link: https://leetcode.com/problems/next-greater-node-in-linked-list/

#include <iostream>
#include <vector>
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
// 1. OPTIMAL APPROACH (Convert to Array + Monotonic Stack)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Extract list values into array arr.
2. Initialize ans of size n with 0.
3. Monotonic decreasing stack st storing indices.
4. For i from 0 to n-1:
     While !st.empty() && arr[i] > arr[st.top()]:
         ans[st.top()] = arr[i]
         st.pop()
     st.push(i)
5. Return ans.
*/

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }

        int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> st; // Stores indices of elements

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] > arr[st.top()]) {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
