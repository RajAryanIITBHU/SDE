// Link: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Count / Frequency Array of Max Gain)
// ==========================================
// Time Complexity  : O(n + m)
// Space Complexity : O(1) (frequency array of gain 1..5)
/*
PSEUDOCODE:
1. sum1 = sum(nums1), sum2 = sum(nums2).
2. If sum1 > sum2 -> swap(nums1, nums2), swap(sum1, sum2) so nums1 is always smaller.
3. diff = sum2 - sum1.
4. If nums1.size() * 6 < nums2.size() * 1 -> return -1 (impossible).
5. For each element in nums1, max gain by increasing = 6 - nums1[i].
6. For each element in nums2, max gain by decreasing = nums2[i] - 1.
7. Store frequency of gains (1 to 5) in gainCount array.
8. Greedily use largest gain (5 down to 1) until diff <= 0.
9. Return operations count.
*/

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        // Impossible check: smallest possible sum of larger array > largest possible sum of smaller array
        if (nums1.size() * 6 < nums2.size() * 1 || nums2.size() * 6 < nums1.size() * 1) {
            return -1;
        }

        int sum1 = 0, sum2 = 0;
        for (int x : nums1) sum1 += x;
        for (int x : nums2) sum2 += x;

        // Ensure sum1 <= sum2
        if (sum1 > sum2) {
            return minOperations(nums2, nums1);
        }

        int diff = sum2 - sum1;
        if (diff == 0) return 0;

        vector<int> gainCount(6, 0); // Max possible gain is 6 - 1 = 5

        for (int x : nums1) {
            gainCount[6 - x]++; // Increase element towards 6
        }
        for (int x : nums2) {
            gainCount[x - 1]++; // Decrease element towards 1
        }

        int operations = 0;

        // Greedily apply largest available gains
        for (int gain = 5; gain >= 1 && diff > 0; gain--) {
            int take = min(gainCount[gain], (diff + gain - 1) / gain);
            operations += take;
            diff -= take * gain;
        }

        return operations;
    }
};
