// Link: https://leetcode.com/problems/rotate-array/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Shift One by One)
// ==========================================
// Time Complexity  : O(n * k)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. k = k % n.
2. Repeat k times:
     Store last element: temp = nums[n-1]
     Shift all elements one position to the right:
         For j from n-1 down to 1: nums[j] = nums[j-1]
     Set nums[0] = temp
*/

class SolutionBruteForce {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        for (int step = 0; step < k; step++) {
            int temp = nums[n - 1];
            for (int j = n - 1; j > 0; j--) {
                nums[j] = nums[j - 1];
            }
            nums[0] = temp;
        }
    }
};

// ==========================================
// 2. BETTER APPROACH (Extra Array)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Create temporary array arr of size n.
2. For i from 0 to n-1:
     arr[(i + k) % n] = nums[i]
3. Copy arr back to nums.
*/

class SolutionBetter {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            arr[(i + k) % n] = nums[i];
        }

        nums = arr;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Reversal Algorithm)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. k = k % n.
2. Reverse entire array: reverse(nums.begin(), nums.end()).
3. Reverse first k elements: reverse(nums.begin(), nums.begin() + k).
4. Reverse remaining (n - k) elements: reverse(nums.begin() + k, nums.end()).
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // Step 1: Reverse entire array
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse remaining n - k elements
        reverse(nums.begin() + k, nums.end());
    }
};
