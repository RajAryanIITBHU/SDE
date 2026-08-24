// Link: https://leetcode.com/problems/lfu-cache/

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

// Node storing key, value, frequency
struct Node {
    int key;
    int val;
    int freq;
    Node(int k, int v) : key(k), val(v), freq(1) {}
};

// ==========================================
// 1. OPTIMAL APPROACH (Double Hash Map + Doubly Linked Lists)
// ==========================================
// Time Complexity  : O(1) for get and put
// Space Complexity : O(capacity)
/*
PSEUDOCODE:
1. Maintain:
     keyToNode: key -> iterator in freqToList[freq]
     freqToList: freq -> list<Node>
     minFreq: current minimum frequency in cache
     cap: capacity
2. get(key):
     if key not in keyToNode -> return -1
     Update node frequency by moving from freqToList[freq] to freqToList[freq+1].
     Update minFreq if old list becomes empty and minFreq == freq.
     return node->val
3. put(key, value):
     if cap == 0 return
     if key in keyToNode:
         update value, update frequency (same as get)
     else:
         if cache is full:
             evict front of freqToList[minFreq], remove from keyToNode
         insert new Node with freq = 1 to freqToList[1]
         minFreq = 1
*/

class LFUCache {
private:
    int cap;
    int minFreq;
    unordered_map<int, list<Node>::iterator> keyToNode;
    unordered_map<int, list<Node>> freqToList;

    void updateFreq(list<Node>::iterator nodeIt) {
        int key = nodeIt->key;
        int val = nodeIt->val;
        int freq = nodeIt->freq;

        freqToList[freq].erase(nodeIt);
        if (freqToList[freq].empty()) {
            freqToList.erase(freq);
            if (minFreq == freq) {
                minFreq++;
            }
        }

        Node updatedNode(key, val);
        updatedNode.freq = freq + 1;
        freqToList[freq + 1].push_back(updatedNode);
        keyToNode[key] = --freqToList[freq + 1].end();
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyToNode.find(key) == keyToNode.end()) {
            return -1;
        }

        auto nodeIt = keyToNode[key];
        int val = nodeIt->val;
        updateFreq(nodeIt);
        return val;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (keyToNode.find(key) != keyToNode.end()) {
            auto nodeIt = keyToNode[key];
            nodeIt->val = value;
            updateFreq(nodeIt);
        } else {
            if ((int)keyToNode.size() == cap) {
                // Evict least frequently used (LRU among least frequent)
                auto lfuNode = freqToList[minFreq].front();
                keyToNode.erase(lfuNode.key);
                freqToList[minFreq].pop_front();
                if (freqToList[minFreq].empty()) {
                    freqToList.erase(minFreq);
                }
            }

            Node newNode(key, value);
            newNode.freq = 1;
            freqToList[1].push_back(newNode);
            keyToNode[key] = --freqToList[1].end();
            minFreq = 1;
        }
    }
};
