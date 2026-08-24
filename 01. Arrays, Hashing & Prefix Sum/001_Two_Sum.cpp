// Link: https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Run an outer loop i from 0 to n-1.
2. Run an inner loop j from i+1 to n-1.
3. If nums[i] + nums[j] == target, return {i, j}.
4. If no pair found, return {}.
*/

class SolutionBruteForce {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};

// ==========================================
// 2. BETTER APPROACH (Sorting + Two Pointers)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Store elements along with original indices: arr = {{nums[0], 0}, {nums[1], 1}, ...}
2. Sort arr in ascending order based on values.
3. Initialize two pointers: left = 0, right = n - 1.
4. While left < right:
     sum = arr[left].first + arr[right].first
     if sum == target -> return {arr[left].second, arr[right].second}
     else if sum < target -> left++
     else -> right--
5. Return {} if no such pair exists.
*/

class SolutionBetter {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> arr(n); // {nums[i], original_index}

        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());

        int left = 0;
        int right = n - 1;

        while (left < right) {
            int sum = arr[left].first + arr[right].first;

            if (sum == target) {
                return {arr[left].second, arr[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Hash Map - One Pass)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Create a hash map 'mp' to store {element, index}.
2. Iterate i from 0 to n-1:
     rem = target - nums[i]
     if rem is present in mp:
         return {mp[rem], i}
     store nums[i] in mp -> mp[nums[i]] = i
3. Return {} if not found.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp; // {nums[i], index}

        for (int i = 0; i < n; i++) {
            int rem = target - nums[i];

            // If remaining element is already seen
            if (mp.find(rem) != mp.end()) {
                return {mp[rem], i};
            }

            // Store current element and index in map
            mp[nums[i]] = i;
        }

        return {};
    }
};
