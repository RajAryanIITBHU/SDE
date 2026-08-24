// Link: https://www.geeksforgeeks.org/problems/lru-cache/1

#include <iostream>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Doubly Linked List + Hash Map)
// ==========================================
// Time Complexity  : get, put: O(1)
// Space Complexity : O(capacity)
/*
PSEUDOCODE:
1. Node: key, value, prev, next.
2. Dummy head and tail nodes.
3. get(key):
     if not in map return -1
     node = map[key]
     moveToHead(node)
     return node->value
4. put(key, value):
     if in map: update value, moveToHead(node)
     else:
         if size == cap:
             lru = removeTail()
             map.erase(lru->key)
         newNode = addHead(key, value)
         map[key] = newNode
*/

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

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

    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    Node* popTail() {
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }

public:
    LRUCache(int cap) {
        this->cap = cap;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int GET(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];
        moveToHead(node);
        return node->value;
    }

    void SET(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            moveToHead(node);
        } else {
            if ((int)mp.size() == cap) {
                Node* lru = popTail();
                mp.erase(lru->key);
                delete lru;
            }

            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            addNode(newNode);
        }
    }
};
