// Link: https://leetcode.com/problems/3sum/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (3 Loops + Set)
// ==========================================
// Time Complexity  : O(n^3 * log(number_of_unique_triplets))
// Space Complexity : O(2 * number_of_unique_triplets)
/*
PSEUDOCODE:
1. Create set<vector<int>> st to store unique triplets.
2. For i from 0 to n-1:
     For j from i+1 to n-1:
         For k from j+1 to n-1:
             if nums[i] + nums[j] + nums[k] == 0:
                 triplet = {nums[i], nums[j], nums[k]}
                 sort triplet
                 st.insert(triplet)
3. Return all triplets from st in vector ans.
*/

class SolutionBruteForce {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        st.insert(triplet);
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Sorting + Two Pointers)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. Sort nums.
2. For i from 0 to n-1:
     // Skip duplicates for first element
     if i > 0 && nums[i] == nums[i-1] -> continue
     
     left = i + 1, right = n - 1
     While left < right:
         sum = nums[i] + nums[left] + nums[right]
         if sum == 0:
             ans.push_back({nums[i], nums[left], nums[right]})
             left++, right--
             // Skip duplicates for second and third elements
             while left < right && nums[left] == nums[left-1] -> left++
             while left < right && nums[right] == nums[right+1] -> right--
         else if sum < 0:
             left++
         else:
             right--
3. Return ans.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            // Skip duplicate values for 1st element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // Skip duplicates for 2nd and 3rd elements
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return ans;
    }
};
