// Link: https://leetcode.com/problems/range-sum-query-immutable/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Loop on Every Query)
// ==========================================
// Time Complexity  : O(n) per query, O(1) constructor
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Store a copy of nums in arr.
2. In sumRange(left, right):
     sum = 0
     For i from left to right: sum += arr[i]
     return sum
*/

class NumArrayBruteForce {
private:
    vector<int> arr;

public:
    NumArrayBruteForce(vector<int>& nums) {
        arr = nums;
    }

    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum += arr[i];
        }
        return sum;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Prefix Sum Array - O(1) Query)
// ==========================================
// Time Complexity  : O(1) per query, O(n) precomputation in constructor
// Space Complexity : O(n) for prefix sum array
/*
PSEUDOCODE:
1. Build prefix sum array PS of size n+1 (1-indexed).
2. PS[0] = 0.
3. For i from 0 to n-1:
     PS[i + 1] = PS[i] + nums[i]
4. In sumRange(left, right):
     return PS[right + 1] - PS[left]
*/

class NumArray {
private:
    vector<int> PS;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        PS.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            PS[i + 1] = PS[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return PS[right + 1] - PS[left];
    }
};
