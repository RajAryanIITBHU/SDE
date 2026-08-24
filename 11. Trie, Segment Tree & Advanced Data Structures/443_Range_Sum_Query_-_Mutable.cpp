// Link: https://leetcode.com/problems/range-sum-query-mutable/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Indexed Tree / Fenwick Tree)
// ==========================================
// Time Complexity  : Constructor: O(n log n), update: O(log n), sumRange: O(log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
Fenwick Tree (BIT):
1. bit array of size n + 1.
2. add(i, delta):
     while i <= n:
         bit[i] += delta
         i += i & (-i)
3. query(i):
     sum = 0
     while i > 0:
         sum += bit[i]
         i -= i & (-i)
     return sum
4. sumRange(left, right): return query(right + 1) - query(left).
*/

class NumArray {
private:
    vector<int> bit;
    vector<int> originalNums;
    int n;

    void add(int i, int delta) {
        while (i <= n) {
            bit[i] += delta;
            i += i & (-i);
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & (-i);
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        originalNums = nums;
        bit.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            add(i + 1, nums[i]);
        }
    }

    void update(int index, int val) {
        int delta = val - originalNums[index];
        originalNums[index] = val;
        add(index + 1, delta);
    }

    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }
};
