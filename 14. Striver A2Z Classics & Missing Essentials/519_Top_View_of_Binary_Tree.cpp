// Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// Definition for binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (BFS Level-Order with Horizontal Distance Map)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Map<int, int> topNode: horizontalDistance -> nodeValue.
2. Queue storing {node, horizontalDistance}.
3. Push {root, 0}.
4. While !q.empty():
     {curr, hd} = q.front(), q.pop()
     if topNode.find(hd) == topNode.end():
         topNode[hd] = curr->data // Only first node seen at hd is top view
     if curr->left: q.push({curr->left, hd - 1})
     if curr->right: q.push({curr->right, hd + 1})
5. Extract map values in order of hd.
6. Return ans.
*/

class Solution {
public:
    vector<int> topView(Node *root) {
        if (root == nullptr) return {};

        map<int, int> topNode; // HD -> Node Data
        queue<pair<Node*, int>> q; // {Node, HD}
        q.push({root, 0});

        while (!q.empty()) {
            auto [curr, hd] = q.front();
            q.pop();

            if (topNode.find(hd) == topNode.end()) {
                topNode[hd] = curr->data;
            }

            if (curr->left != nullptr) {
                q.push({curr->left, hd - 1});
            }
            if (curr->right != nullptr) {
                q.push({curr->right, hd + 1});
            }
        }

        vector<int> ans;
        for (auto& p : topNode) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
