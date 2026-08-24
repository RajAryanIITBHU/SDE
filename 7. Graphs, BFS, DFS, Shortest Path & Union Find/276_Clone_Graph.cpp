// Link: https://leetcode.com/problems/clone-graph/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// ==========================================
// 1. OPTIMAL APPROACH (DFS Traversal + Cloned Map)
// ==========================================
// Time Complexity  : O(V + E)
// Space Complexity : O(V)
/*
PSEUDOCODE:
1. Maintain clonedMap: originalNode -> clonedNode.
2. Helper dfs(node):
     if node == nullptr return nullptr
     if node in clonedMap return clonedMap[node]
     clone = new Node(node->val)
     clonedMap[node] = clone
     For each neighbor in node->neighbors:
         clone->neighbors.push_back(dfs(neighbor))
     return clone
3. Return dfs(node).
*/

class Solution {
private:
    unordered_map<Node*, Node*> clonedMap;

public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        // If already cloned, return the cloned instance
        if (clonedMap.find(node) != clonedMap.end()) {
            return clonedMap[node];
        }

        Node* clone = new Node(node->val);
        clonedMap[node] = clone;

        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};
