/*
 * ============================================================================
 * Concept: Top-K Elements Pattern
 * Subtopic: Greedy Algorithms, Heap & Priority Queue
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Finds K largest, smallest, or most frequent elements.
Uses Min-Heap of size K to find K largest elements (or Max-Heap of size K for K smallest).
Alternatively, QuickSelect algorithm achieves $O(N)$ average time.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N log K) using Heap of size K, O(N) average using QuickSelect.
 * - Space Complexity: O(K) auxiliary heap space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Kth Largest Element in an Array (LC 215).
- Top K Frequent Elements (LC 347).
- K Closest Points to Origin (LC 973).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Top K Frequent Elements (LC 347).
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    for (int num : nums) counts[num]++;

    // Min-heap storing pair {frequency, num}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto& pair : counts) {
        pq.push({pair.second, pair.first});
        if ((int)pq.size() > k) pq.pop();
    }

    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    auto res = topKFrequent(nums, 2);
    cout << "Top 2 Frequent: " << res[0] << ", " << res[1] << "\n";
    return 0;
}
