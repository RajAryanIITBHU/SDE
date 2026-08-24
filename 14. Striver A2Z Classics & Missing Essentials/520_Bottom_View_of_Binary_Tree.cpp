// Link: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

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
// 1. OPTIMAL APPROACH (BFS Level-Order with Overwritten Horizontal Distance Map)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Map<int, int> bottomNode: horizontalDistance -> nodeValue.
2. Queue storing {node, horizontalDistance}.
3. Push {root, 0}.
4. While !q.empty():
     {curr, hd} = q.front(), q.pop()
     bottomNode[hd] = curr->data // Overwrite to store the latest (bottom-most) node
     if curr->left: q.push({curr->left, hd - 1})
     if curr->right: q.push({curr->right, hd + 1})
5. Extract map values in order of hd.
6. Return ans.
*/

class Solution {
public:
    vector<int> bottomView(Node *root) {
        if (root == nullptr) return {};

        map<int, int> bottomNode; // HD -> Node Data
        queue<pair<Node*, int>> q; // {Node, HD}
        q.push({root, 0});

        while (!q.empty()) {
            auto [curr, hd] = q.front();
            q.pop();

            // Always update to retain the deepest node for that vertical column
            bottomNode[hd] = curr->data;

            if (curr->left != nullptr) {
                q.push({curr->left, hd - 1});
            }
            if (curr->right != nullptr) {
                q.push({curr->right, hd + 1});
            }
        }

        vector<int> ans;
        for (auto& p : bottomNode) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
