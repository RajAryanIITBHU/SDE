// Link: https://leetcode.com/problems/lru-cache/

#include <iostream>
#include <unordered_map>

using namespace std;

// Doubly Linked List Node
struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Hash Map + Doubly Linked List)
// ==========================================
// Time Complexity  : O(1) for get and put
// Space Complexity : O(capacity)
/*
PSEUDOCODE:
1. Maintain head and tail dummy nodes, and mp: key -> Node*.
2. Helper addNode(node): inserts node right after head (most recently used).
3. Helper removeNode(node): unlinks node from list.
4. get(key):
     if key not in mp -> return -1
     node = mp[key]
     removeNode(node), addNode(node) (mark as MRU)
     return node->val
5. put(key, value):
     if key in mp:
         node = mp[key], node->val = value
         removeNode(node), addNode(node)
     else:
         if mp.size() == capacity:
             lruNode = tail->prev
             removeNode(lruNode)
             mp.erase(lruNode->key)
             delete lruNode
         newNode = new Node(key, value)
         addNode(newNode)
         mp[key] = newNode
*/

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];
        removeNode(node);
        addNode(node); // Move to head (MRU)
        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            removeNode(node);
            addNode(node);
        } else {
            if ((int)mp.size() == cap) {
                Node* lru = tail->prev;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
            }

            Node* newNode = new Node(key, value);
            addNode(newNode);
            mp[key] = newNode;
        }
    }
};
