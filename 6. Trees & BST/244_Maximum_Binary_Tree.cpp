// Link: https://leetcode.com/problems/maximum-binary-tree/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Monotonic Decreasing Stack)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain vector<TreeNode*> st as stack.
2. For each num in nums:
     curr = new TreeNode(num)
     While !st.empty() && st.back()->val < num:
         curr->left = st.back() // The smaller preceding root becomes left child of curr
         st.pop_back()
     if !st.empty():
         st.back()->right = curr // curr becomes right child of the larger predecessor
     st.push_back(curr)
3. Return st.front() (the absolute maximum element is the root of the tree).
*/

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> st;

        for (int num : nums) {
            TreeNode* curr = new TreeNode(num);

            while (!st.empty() && st.back()->val < num) {
                curr->left = st.back();
                st.pop_back();
            }

            if (!st.empty()) {
                st.back()->right = curr;
            }

            st.push_back(curr);
        }

        return st.front();
    }
};
