// Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Parent Mapping + BFS Radial Expansion)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Build parent pointers map using DFS/BFS: parentMap[node] = parentNode.
2. Radial BFS starting from target node:
     queue<TreeNode*> q, push target, visited set containing target, currentDistance = 0.
     While !q.empty() && currentDistance < k:
         For each node in current level:
             Check node->left, node->right, and parentMap[node].
             If not visited, add to queue and mark visited.
         currentDistance++
3. Collect all nodes in queue as answer.
4. Return ans.
*/

class Solution {
private:
    void buildParentMap(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (root == nullptr) return;

        parentMap[root] = parent;
        buildParentMap(root->left, root, parentMap);
        buildParentMap(root->right, root, parentMap);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        buildParentMap(root, nullptr, parentMap);

        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;

        q.push(target);
        vis.insert(target);
        int currentDistance = 0;

        while (!q.empty() && currentDistance < k) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // Explore left child
                if (curr->left != nullptr && vis.find(curr->left) == vis.end()) {
                    vis.insert(curr->left);
                    q.push(curr->left);
                }
                // Explore right child
                if (curr->right != nullptr && vis.find(curr->right) == vis.end()) {
                    vis.insert(curr->right);
                    q.push(curr->right);
                }
                // Explore parent
                if (parentMap[curr] != nullptr && vis.find(parentMap[curr]) == vis.end()) {
                    vis.insert(parentMap[curr]);
                    q.push(parentMap[curr]);
                }
            }

            currentDistance++;
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
