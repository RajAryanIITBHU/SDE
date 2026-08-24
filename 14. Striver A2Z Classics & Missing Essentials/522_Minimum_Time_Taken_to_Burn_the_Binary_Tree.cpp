// Link: https://www.geeksforgeeks.org/problems/burning-tree/1

#include <iostream>
#include <unordered_map>
#include <unordered_set>
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
// 1. OPTIMAL APPROACH (Parent Pointer Hash Map + BFS Burning Simulation)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Map parent pointers for all nodes; locate targetNode.
2. BFS starting from targetNode infecting (left, right, parent).
3. Track time taken for tree to completely burn.
4. Return time.
*/

class Solution {
private:
    Node* mapParents(Node* root, unordered_map<Node*, Node*>& parentTrack, int target) {
        queue<Node*> q;
        q.push(root);
        Node* targetNode = nullptr;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->data == target) {
                targetNode = curr;
            }

            if (curr->left != nullptr) {
                parentTrack[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                parentTrack[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return targetNode;
    }

public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentTrack;
        Node* targetNode = mapParents(root, parentTrack, target);

        unordered_set<Node*> vis;
        queue<Node*> q;

        q.push(targetNode);
        vis.insert(targetNode);

        int time = 0;

        while (!q.empty()) {
            int sz = q.size();
            bool burnedNew = false;

            for (int i = 0; i < sz; i++) {
                Node* curr = q.front();
                q.pop();

                // Left child
                if (curr->left && vis.find(curr->left) == vis.end()) {
                    burnedNew = true;
                    vis.insert(curr->left);
                    q.push(curr->left);
                }

                // Right child
                if (curr->right && vis.find(curr->right) == vis.end()) {
                    burnedNew = true;
                    vis.insert(curr->right);
                    q.push(curr->right);
                }

                // Parent
                if (parentTrack[curr] && vis.find(parentTrack[curr]) == vis.end()) {
                    burnedNew = true;
                    vis.insert(parentTrack[curr]);
                    q.push(parentTrack[curr]);
                }
            }

            if (burnedNew) {
                time++;
            }
        }

        return time;
    }
};
