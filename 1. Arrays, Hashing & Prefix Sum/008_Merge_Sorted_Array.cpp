// Link: https://leetcode.com/problems/merge-sorted-array/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Append & Sort)
// ==========================================
// Time Complexity  : O((m + n) log (m + n))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Copy all elements of nums2 into nums1 starting at index m.
2. Sort nums1: sort(nums1.begin(), nums1.end()).
*/

class SolutionBruteForce {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }
};

// ==========================================
// 2. BETTER APPROACH (Extra Array + Two Pointers)
// ==========================================
// Time Complexity  : O(m + n)
// Space Complexity : O(m + n) auxiliary space
/*
PSEUDOCODE:
1. Create a temporary array arr of size m + n.
2. Use pointers i = 0 (for nums1) and j = 0 (for nums2).
3. Compare nums1[i] and nums2[j], push smaller element to arr.
4. Copy remaining elements from nums1 or nums2 into arr.
5. Assign nums1 = arr.
*/

class SolutionBetter {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> arr;
        int i = 0;
        int j = 0;

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            } else {
                arr.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            arr.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            arr.push_back(nums2[j]);
            j++;
        }

        nums1 = arr;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Three Pointers from Back)
// ==========================================
// Time Complexity  : O(m + n)
// Space Complexity : O(1) in-place
/*
PSEUDOCODE:
1. Initialize pointers:
     i = m - 1 (last valid element in nums1)
     j = n - 1 (last element in nums2)
     k = m + n - 1 (last position in nums1)
2. While j >= 0:
     a. If i >= 0 && nums1[i] > nums2[j]:
          nums1[k] = nums1[i]
          i--
     b. Else:
          nums1[k] = nums2[j]
          j--
     k--
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        // Place larger elements from the end
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};
