/*
 * ============================================================================
 * Concept: Segment Tree (Range Queries & Lazy Propagation)
 * Subtopic: Trie, Segment Tree & Advanced Data Structures
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Binary tree data structure supporting arbitrary range minimum/maximum/sum queries and point/range updates in $O(\log N)$ time.
Lazy Propagation defers range updates to child nodes until accessed, ensuring $O(\log N)$ range update performance.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(log N) range query and range update.
 * - Space Complexity: O(4 * N) tree array space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Range Sum Query - Mutable (LC 307).
- Range Minimum / Maximum Queries.
- Falling Squares / Skyline Problem.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Segment Tree for Range Sum Query with Point Updates.
 */

#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(nums, 2 * node, start, mid);
        build(nums, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void updateTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) updateTree(2 * node, start, mid, idx, val);
        else updateTree(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int queryTree(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        return queryTree(2 * node, start, mid, l, r) + queryTree(2 * node + 1, mid + 1, end, l, r);
    }
public:
    SegmentTree(const vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n, 0);
        if (n > 0) build(nums, 1, 0, n - 1);
    }

    void update(int idx, int val) { updateTree(1, 0, n - 1, idx, val); }
    int query(int l, int r) { return queryTree(1, 0, n - 1, l, r); }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    SegmentTree st(nums);
    cout << "Range Sum [1..3]: " << st.query(1, 3) << "\n"; // 3 + 5 + 7 = 15
    st.update(1, 10);
    cout << "Updated Sum [1..3]: " << st.query(1, 3) << "\n"; // 10 + 5 + 7 = 22
    return 0;
}
