// Link: https://leetcode.com/problems/most-frequent-subtree-sum/

#include <iostream>
#include <vector>
#include <unordered_map>
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
// 1. OPTIMAL APPROACH (Postorder DFS + Frequency Map)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain freqMap: subtreeSum -> count, maxFreq = 0.
2. Helper getSubtreeSum(root):
     if root == nullptr return 0
     sum = root->val + getSubtreeSum(root->left) + getSubtreeSum(root->right)
     freqMap[sum]++
     maxFreq = max(maxFreq, freqMap[sum])
     return sum
3. Collect all sums with frequency == maxFreq into ans.
4. Return ans.
*/

class Solution {
private:
    unordered_map<int, int> freqMap;
    int maxFreq = 0;

    int getSubtreeSum(TreeNode* root) {
        if (root == nullptr) return 0;

        int sum = root->val + getSubtreeSum(root->left) + getSubtreeSum(root->right);
        freqMap[sum]++;
        maxFreq = max(maxFreq, freqMap[sum]);

        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        getSubtreeSum(root);

        vector<int> ans;
        for (auto& p : freqMap) {
            if (p.second == maxFreq) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};
