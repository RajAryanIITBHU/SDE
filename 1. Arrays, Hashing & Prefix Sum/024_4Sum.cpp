// Link: https://leetcode.com/problems/4sum/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (4 Loops + Set)
// ==========================================
// Time Complexity  : O(n^4)
// Space Complexity : O(2 * number_of_unique_quads)
/*
PSEUDOCODE:
1. Create set<vector<int>> st.
2. 4 nested loops i, j, k, l.
3. If sum == target, sort and insert into st.
4. Return vector of quads.
*/

class SolutionBruteForce {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                        if (sum == target) {
                            vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                            sort(quad.begin(), quad.end());
                            st.insert(quad);
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Sorting + 2 Loops + Two Pointers)
// ==========================================
// Time Complexity  : O(n^3)
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. Sort nums.
2. For i from 0 to n-1:
     Skip duplicates for i.
     For j from i+1 to n-1:
         Skip duplicates for j.
         left = j + 1, right = n - 1
         While left < right:
             sum = nums[i] + nums[j] + nums[left] + nums[right]
             if sum == target:
                 ans.push_back({nums[i], nums[j], nums[left], nums[right]})
                 left++, right--
                 Skip duplicates for left and right.
             else if sum < target:
                 left++
             else:
                 right--
3. Return ans.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            // Avoid duplicates for 1st number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                // Avoid duplicates for 2nd number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        // Skip duplicates for 3rd and 4th numbers
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};
