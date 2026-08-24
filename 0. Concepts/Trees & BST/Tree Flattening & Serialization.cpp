/*
 * ============================================================================
 * Concept: Serialize and Deserialize Binary Tree
 * Subtopic: Trees & BST
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Converts a binary tree into a string representation and reconstructs the tree back.
Preorder DFS representation with `null` markers (e.g. `1,2,#,#,3,4,#,#,5,#,#`) allows unambiguous tree reconstruction.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time complexity.
 * - Space Complexity: O(N) space for string and queue.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Serialize and Deserialize Binary Tree (LC 297).
- Flatten Binary Tree to Linked List (LC 114).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Preorder String Serialization and Deserialization.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    void serializeDFS(TreeNode* root, stringstream& ss) {
        if (!root) { ss << "# "; return; }
        ss << root->val << " ";
        serializeDFS(root->left, ss);
        serializeDFS(root->right, ss);
    }

    string serialize(TreeNode* root) {
        stringstream ss;
        serializeDFS(root, ss);
        return ss.str();
    }

    TreeNode* deserializeDFS(stringstream& ss) {
        string valStr;
        if (!(ss >> valStr) || valStr == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(valStr));
        node->left = deserializeDFS(ss);
        node->right = deserializeDFS(ss);
        return node;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeDFS(ss);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Codec codec;
    string serialized = codec.serialize(root);
    cout << "Serialized Tree: " << serialized << "\n";
    TreeNode* deserialized = codec.deserialize(serialized);
    cout << "Deserialized Root: " << deserialized->val << "\n";
    return 0;
}
