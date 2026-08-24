// Link: https://leetcode.com/problems/path-sum-iii/

#include <iostream>
#include <unordered_map>

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
// 1. OPTIMAL APPROACH (Prefix Sum Hash Map + DFS Backtracking)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(h) recursion stack + O(n) map
/*
PSEUDOCODE:
1. Maintain prefixSumCount map: prefixSum -> frequency.
2. Initialize prefixSumCount[0] = 1.
3. Helper dfs(root, currentSum, targetSum):
     if root == nullptr return 0
     currentSum += root->val
     paths = prefixSumCount[currentSum - targetSum]
     prefixSumCount[currentSum]++
     paths += dfs(root->left, currentSum, targetSum)
     paths += dfs(root->right, currentSum, targetSum)
     prefixSumCount[currentSum]-- // Backtrack
     return paths
4. Return dfs(root, 0, targetSum).
*/

class Solution {
private:
    unordered_map<long long, int> prefixSumCount;

    int dfs(TreeNode* root, long long currentSum, int targetSum) {
        if (root == nullptr) return 0;

        currentSum += root->val;
        int paths = 0;

        if (prefixSumCount.find(currentSum - targetSum) != prefixSumCount.end()) {
            paths += prefixSumCount[currentSum - targetSum];
        }

        prefixSumCount[currentSum]++;

        paths += dfs(root->left, currentSum, targetSum);
        paths += dfs(root->right, currentSum, targetSum);

        prefixSumCount[currentSum]--; // Backtrack

        return paths;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        prefixSumCount[0] = 1;
        return dfs(root, 0, targetSum);
    }
};
