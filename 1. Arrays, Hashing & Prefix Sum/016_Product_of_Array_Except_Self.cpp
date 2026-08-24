// Link: https://leetcode.com/problems/product-of-array-except-self/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Nested Loop Multiplication)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. Initialize ans of size n.
2. For i from 0 to n-1:
     prod = 1
     For j from 0 to n-1:
         if i != j:
             prod *= nums[j]
     ans[i] = prod
3. Return ans.
*/

class SolutionBruteForce {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    prod *= nums[j];
                }
            }
            ans[i] = prod;
        }

        return ans;
    }
};

// ==========================================
// 2. BETTER APPROACH (Prefix & Suffix Product Arrays)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n) auxiliary space
/*
PSEUDOCODE:
1. Create pref and suff arrays of size n.
2. pref[0] = 1, suff[n-1] = 1.
3. Compute pref: pref[i] = pref[i-1] * nums[i-1].
4. Compute suff: suff[i] = suff[i+1] * nums[i+1].
5. ans[i] = pref[i] * suff[i].
6. Return ans.
*/

class SolutionBetter {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 1);
        vector<int> suff(n, 1);
        vector<int> ans(n);

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = pref[i] * suff[i];
        }

        return ans;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Prefix in Output + Running Suffix)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. Initialize ans of size n with ans[0] = 1.
2. First pass (Left to Right):
     For i from 1 to n-1:
         ans[i] = ans[i-1] * nums[i-1]
3. Second pass (Right to Left):
     suffix = 1
     For i from n-1 down to 0:
         ans[i] = ans[i] * suffix
         suffix *= nums[i]
4. Return ans.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Step 1: Compute prefix products in ans
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Step 2: Multiply by running suffix product
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = ans[i] * suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
