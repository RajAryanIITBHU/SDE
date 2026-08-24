/*
 * ============================================================================
 * Concept: Median of Two Sorted Arrays (Partition Search)
 * Subtopic: Binary Search & Search on Answer
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Finds the median of two sorted arrays `nums1` (size M) and `nums2` (size N) in O(log(min(M, N))) time.
Partitions both arrays into left and right halves such that `left_len == right_len` and `max(left1, left2) <= min(right1, right2)`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(log(min(M, N))) time complexity.
 * - Space Complexity: O(1) space complexity.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Finding median or K-th smallest element in two sorted arrays.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Median of Two Sorted Arrays (LC 4).
2. K-th Smallest Element of Two Sorted Arrays.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

    int m = nums1.size(), n = nums2.size();
    int low = 0, high = m;

    while (low <= high) {
        int i = low + (high - low) / 2;
        int j = (m + n + 1) / 2 - i;

        int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int minRight1 = (i == m) ? INT_MAX : nums1[i];

        int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int minRight2 = (j == n) ? INT_MAX : nums2[j];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((m + n) % 2 == 0) {
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            } else {
                return max(maxLeft1, maxLeft2);
            }
        } else if (maxLeft1 > minRight2) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }
    return 0.0;
}

int main() {
    vector<int> a = {1, 3}, b = {2};
    cout << "Median: " << findMedianSortedArrays(a, b) << "\n";
    return 0;
}
