// Link: https://leetcode.com/problems/tuple-with-same-product/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Pair Product Frequency Map)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n^2)
/*
PSEUDOCODE:
1. Create hash map mp: product -> count_of_pairs.
2. For i from 0 to n-1:
     For j from i+1 to n-1:
         prod = nums[i] * nums[j]
         mp[prod]++
3. For each count in mp:
     If count >= 2:
         Number of combinations of 2 pairs = count * (count - 1) / 2
         Each combination can form 8 distinct tuples (a,b,c,d)
         ans += (count * (count - 1) / 2) * 8
4. Return ans.
*/

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp; // {product, frequency}

        // Count frequency of every pair product
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int prod = nums[i] * nums[j];
                mp[prod]++;
            }
        }

        int ans = 0;

        // Each 2 pairs with same product can form 8 tuples
        for (auto& it : mp) {
            int count = it.second;
            if (count >= 2) {
                ans += (count * (count - 1) / 2) * 8;
            }
        }

        return ans;
    }
};
