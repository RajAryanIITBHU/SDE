/*
 * ============================================================================
 * Concept: Heap Operations & Custom Comparators in C++
 * Subtopic: Greedy Algorithms, Heap & Priority Queue
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Priority Queue (`std::priority_queue`) provides $O(\log N)$ push/pop and $O(1)$ top access.
- Max-Heap (Default): `priority_queue<int> pq;`
- Min-Heap: `priority_queue<int, vector<int>, greater<int>> pq;`
- Custom Lambda Comparator: `auto comp = [](auto& a, auto& b) { return a.val > b.val; }; priority_queue<T, vector<T>, decltype(comp)> pq(comp);`
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(log N) push/pop, O(1) top.
 * - Space Complexity: O(N) space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Custom struct priority queues.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Custom Min-Heap Priority Queue.
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x, y;
    int distSq() const { return x * x + y * y; }
};

int main() {
    auto comp = [](const Point& a, const Point& b) {
        return a.distSq() > b.distSq(); // Min-Heap by distance
    };
    priority_queue<Point, vector<Point>, decltype(comp)> pq(comp);
    pq.push({3, 3});
    pq.push({5, -1});
    pq.push({-2, 4});

    cout << "Closest Point: (" << pq.top().x << ", " << pq.top().y << ")\n";
    return 0;
}
