// Link: https://leetcode.com/problems/majority-element-ii/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Frequency Count)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize vector ans.
2. For i from 0 to n-1:
     if nums[i] is already in ans -> continue
     count = 0
     For j from 0 to n-1:
         if nums[j] == nums[i] -> count++
     if count > n / 3 -> ans.push_back(nums[i])
3. Return ans.
*/

class SolutionBruteForce {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            bool alreadyInAns = false;
            for (int x : ans) {
                if (x == nums[i]) alreadyInAns = true;
            }
            if (alreadyInAns) continue;

            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) count++;
            }

            if (count > n / 3) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};

// ==========================================
// 2. BETTER APPROACH (Hash Map)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Count frequencies using hash map mp.
2. For each {element, count} in mp:
     if count > n / 3 -> ans.push_back(element)
3. Return ans.
*/

class SolutionBetter {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int x : nums) {
            mp[x]++;
        }

        for (auto& it : mp) {
            if (it.second > n / 3) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Extended Boyer-Moore Voting - at most 2 candidates)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Maintain cand1, count1 = 0, cand2, count2 = 0.
2. Pass 1 (Candidate Selection):
     For each x in nums:
         if x == cand1 -> count1++
         else if x == cand2 -> count2++
         else if count1 == 0 -> cand1 = x, count1 = 1
         else if count2 == 0 -> cand2 = x, count2 = 1
         else -> count1--, count2--
3. Pass 2 (Verification):
     Count actual occurrences of cand1 and cand2.
     If count > n / 3 -> add to ans.
4. Return ans.
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cand1 = 0, count1 = 0;
        int cand2 = 0, count2 = 0;

        // Step 1: Find potential candidates
        for (int x : nums) {
            if (count1 > 0 && x == cand1) {
                count1++;
            } else if (count2 > 0 && x == cand2) {
                count2++;
            } else if (count1 == 0) {
                cand1 = x;
                count1 = 1;
            } else if (count2 == 0) {
                cand2 = x;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verify candidates
        count1 = 0;
        count2 = 0;
        for (int x : nums) {
            if (x == cand1) count1++;
            else if (x == cand2) count2++;
        }

        vector<int> ans;
        if (count1 > n / 3) ans.push_back(cand1);
        if (count2 > n / 3) ans.push_back(cand2);

        return ans;
    }
};
