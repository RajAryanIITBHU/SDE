// Link: https://leetcode.com/problems/summary-ranges/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Single Pass Range Identification)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. Initialize ans.
2. i = 0.
3. While i < n:
     start = nums[i]
     While i + 1 < n and nums[i + 1] == nums[i] + 1:
         i++
     if start == nums[i]:
         ans.push_back(to_string(start))
     else:
         ans.push_back(to_string(start) + "->" + to_string(nums[i]))
     i++
4. Return ans.
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        int i = 0;

        while (i < n) {
            int start = nums[i];

            // Extend range as long as elements are consecutive
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }

            // Single number range vs interval range
            if (start == nums[i]) {
                ans.push_back(to_string(start));
            } else {
                ans.push_back(to_string(start) + "->" + to_string(nums[i]));
            }

            i++;
        }

        return ans;
    }
};
