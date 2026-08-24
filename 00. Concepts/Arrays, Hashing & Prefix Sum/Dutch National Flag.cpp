/*
 * ============================================================================
 * Concept: Dutch National Flag Algorithm (3-Way Partitioning)
 * Subtopic: Arrays, Hashing & Prefix Sum
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Dutch National Flag algorithm partitions an array into three sections based on a pivot value (or sort 0s, 1s, 2s).
Maintains three pointers: `low`, `mid`, `high`.
- `[0 ... low-1]`: elements < pivot (e.g., 0)
- `[low ... mid-1]`: elements == pivot (e.g., 1)
- `[mid ... high]`: unexamined elements
- `[high+1 ... n-1]`: elements > pivot (e.g., 2)
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) - single pass.
 * - Space Complexity: O(1) - in-place swaps.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Sort array containing only 3 distinct values (e.g. 0, 1, 2).
- Partitioning array around a target value / pivot in QuickSort.
- Move all negative numbers to left, zero in middle, positive to right.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Sort Colors (LC 75: 0s, 1s, 2s).
2. Wiggle Sort / Partition around range [L, R].
3. QuickSort Partition step (3-way partition to handle duplicates efficiently).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    cout << "Sorted Colors: ";
    for (int x : nums) cout << x << " ";
    cout << "\n";
    return 0;
}
