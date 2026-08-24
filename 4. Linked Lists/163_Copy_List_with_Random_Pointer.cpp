// Link: https://leetcode.com/problems/copy-list-with-random-pointer/

#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// ==========================================
// 1. BETTER APPROACH (Hash Map)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Create hash map mp: originalNode -> clonedNode.
2. Pass 1: Clone all nodes and store in map.
3. Pass 2: Set clonedNode->next = mp[curr->next] and clonedNode->random = mp[curr->random].
4. Return mp[head].
*/

class SolutionBetter {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;
        Node* curr = head;

        while (curr != nullptr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr != nullptr) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Interleave & Split - O(1) Auxiliary Space)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Step 1 (Interleave):
     For each node A, create clone A' and insert between A and A->next:
     A -> A' -> B -> B'...
2. Step 2 (Connect Randoms):
     curr = head
     While curr != nullptr:
         if curr->random != nullptr:
             curr->next->random = curr->random->next
         curr = curr->next->next
3. Step 3 (Separate Lists):
     Restore original list and extract cloned list.
4. Return clonedHead.
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        // Step 1: Interleave cloned nodes
        Node* curr = head;
        while (curr != nullptr) {
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        // Step 2: Assign random pointers to cloned nodes
        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate original and cloned lists
        Node* dummy = new Node(0);
        Node* cloneTail = dummy;
        curr = head;

        while (curr != nullptr) {
            Node* clone = curr->next;
            curr->next = clone->next; // Restore original link

            cloneTail->next = clone;
            cloneTail = clone;

            curr = curr->next;
        }

        Node* clonedHead = dummy->next;
        delete dummy;
        return clonedHead;
    }
};
