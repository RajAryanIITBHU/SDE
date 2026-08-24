/*
 * ============================================================================
 * Concept: Prefix Sum & Difference Arrays
 * Subtopic: Arrays, Hashing & Prefix Sum
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Prefix Sum precomputes cumulative sums to allow O(1) range sum queries `sum(L, R) = P[R+1] - P[L]`.
Difference Array allows O(1) range updates `[L, R] += val` by setting `D[L] += val` and `D[R+1] -= val`, followed by prefix sum reconstruction.
2D Prefix Sum allows O(1) submatrix sum queries over `(r1, c1)` to `(r2, c2)`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: Precomputation: O(N) or O(N*M). Query/Update: O(1).
 * - Space Complexity: O(N) or O(N*M) extra space for prefix table.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Frequent range sum queries on static array.
- Frequent range updates `+val` over ranges `[L, R]`, then query final values.
- Count subarrays with sum equal to K (Prefix Sum + Hash Map).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Subarray Sum Equals K (LC 560: Prefix Sum + Frequency Hash Map).
2. 2D Range Sum Query Immutable (LC 304).
3. Corporate Flight Bookings / Car Pooling (Difference Array).
4. Product of Array Except Self (Prefix Product & Suffix Product).
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 1D Prefix Sum for Subarray Sum Equals K
int subarraySum(const vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1; // base case: empty prefix sum is 0
    int current_sum = 0, count = 0;

    for (int num : nums) {
        current_sum += num;
        if (prefixCount.count(current_sum - k)) {
            count += prefixCount[current_sum - k];
        }
        prefixCount[current_sum]++;
    }
    return count;
}

// Difference Array for Range Updates
vector<int> rangeUpdates(int n, const vector<vector<int>>& updates) {
    vector<int> diff(n + 1, 0);
    for (const auto& u : updates) {
        int l = u[0], r = u[1], val = u[2];
        diff[l] += val;
        diff[r + 1] -= val;
    }
    vector<int> result(n);
    int current = 0;
    for (int i = 0; i < n; ++i) {
        current += diff[i];
        result[i] = current;
    }
    return result;
}

int main() {
    vector<int> nums = {1, 1, 1};
    cout << "Subarrays with sum 2: " << subarraySum(nums, 2) << "\n";
    vector<vector<int>> updates = {{1, 3, 2}, {2, 4, 3}};
    auto res = rangeUpdates(5, updates);
    cout << "Updated Array: ";
    for (int x : res) cout << x << " ";
    cout << "\n";
    return 0;
}
