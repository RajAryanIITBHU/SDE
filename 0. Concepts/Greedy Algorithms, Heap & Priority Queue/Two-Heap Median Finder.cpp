/*
 * ============================================================================
 * Concept: Two-Heap Pattern (Continuous Stream Median)
 * Subtopic: Greedy Algorithms, Heap & Priority Queue
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Tracks continuous median in a stream of numbers.
Maintains two heaps:
1. Max-Heap (`small`): Stores lower half of numbers.
2. Min-Heap (`large`): Stores upper half of numbers.
Property: `small.size() == large.size()` OR `small.size() == large.size() + 1`.
Median = `small.top()` (if odd size) OR `(small.top() + large.top()) / 2.0` (if even size).
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(log N) per insert, O(1) for median query.
 * - Space Complexity: O(N) space complexity.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Find Median from Data Stream (LC 295).
- Sliding Window Median (LC 480).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Continuous Stream Median Finder (LC 295).
 */

#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> small; // Max-heap
    priority_queue<int, vector<int>, greater<int>> large; // Min-heap
public:
    MedianFinder() {}

    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();

        if (small.size() < large.size()) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() > large.size()) return small.top();
        return (small.top() + large.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1); mf.addNum(2);
    cout << "Median: " << mf.findMedian() << "\n"; // 1.5
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << "\n"; // 2.0
    return 0;
}
