/*
 * ============================================================================
 * Concept: LRU & LFU Cache Design
 * Subtopic: Stack, Queue, Monotonic Stack & Design
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * High-frequency Microsoft System Design-Lite data structures:
1. LRU Cache (LC 146): O(1) `get` and `put`. Uses `std::unordered_map<key, list<pair<key, val>>::iterator>` and `std::list` (Doubly Linked List).
2. LFU Cache (LC 460): O(1) `get` and `put`. Uses key-to-val map, key-to-freq map, and freq-to-doubly_linked_list map with `minFreq` tracker.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(1) time complexity for get and put.
 * - Space Complexity: O(Capacity) space complexity.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - LRU Cache (LC 146).
- LFU Cache (LC 460).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. LRU Cache implementation using hash map + doubly linked list (`std::list`).
 */

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        if (!mp.count(key)) return -1;
        cache.splice(cache.begin(), cache, mp[key]); // Move node to front
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            mp[key]->second = value;
            cache.splice(cache.begin(), cache, mp[key]);
            return;
        }
        if ((int)cache.size() == cap) {
            int delKey = cache.back().first;
            cache.pop_back();
            mp.erase(delKey);
        }
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};

int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << "Get 1: " << lru.get(1) << "\n"; // 1
    lru.put(3, 3); // evicts key 2
    cout << "Get 2: " << lru.get(2) << "\n"; // -1
    return 0;
}
