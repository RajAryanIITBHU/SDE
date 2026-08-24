/*
 * ============================================================================
 * Concept: Fenwick Tree (Binary Indexed Tree)
 * Subtopic: Trie, Segment Tree & Advanced Data Structures
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Data structure maintaining cumulative prefix sums over an array allowing both point updates and prefix sum queries in $O(\log N)$ time.
Key Bitwise Index Traversals:
- Next parent to update: `i += (i & -i)`
- Previous parent to query: `i -= (i & -i)`
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(log N) per point update and range query.
 * - Space Complexity: O(N) space for BIT array.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Range Sum Query Mutable (LC 307).
- Count of Smaller Numbers After Self (LC 315).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Fenwick Tree Implementation.
 */

#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int n;
public:
    FenwickTree(int size) : tree(size + 1, 0), n(size) {}

    void update(int i, int delta) {
        for (i = i + 1; i <= n; i += (i & -i)) tree[i] += delta;
    }

    int query(int i) {
        int sum = 0;
        for (i = i + 1; i > 0; i -= (i & -i)) sum += tree[i];
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    FenwickTree bit(5);
    bit.update(0, 1);
    bit.update(1, 3);
    bit.update(2, 5);
    cout << "Range Sum [0..2]: " << bit.rangeQuery(0, 2) << "\n"; // 9
    return 0;
}
