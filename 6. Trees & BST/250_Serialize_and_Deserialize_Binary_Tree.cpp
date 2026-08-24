// Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Preorder DFS with StringStream)
// ==========================================
// Time Complexity  : O(n) for serialize and deserialize
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. serialize(root):
     if root == nullptr return "#,"
     return to_string(root->val) + "," + serialize(root->left) + serialize(root->right)
2. deserialize(data):
     stringstream ss(data)
     helper deserializeHelper(ss):
         getline(ss, token, ',')
         if token == "#" return nullptr
         root = new TreeNode(stoi(token))
         root->left = deserializeHelper(ss)
         root->right = deserializeHelper(ss)
         return root
*/

class Codec {
private:
    void serializeHelper(TreeNode* root, string& s) {
        if (root == nullptr) {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    TreeNode* deserializeHelper(stringstream& ss) {
        string token;
        if (!getline(ss, token, ',')) return nullptr;

        if (token == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(token));
        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);

        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        serializeHelper(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};
