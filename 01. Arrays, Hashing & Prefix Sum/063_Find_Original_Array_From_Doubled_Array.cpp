// Link: https://leetcode.com/problems/find-original-array-from-doubled-array/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sorting + Frequency Map)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. If n is odd -> return {}.
2. Sort changed array.
3. Build frequency map mp for elements in changed.
4. Initialize ans.
5. For each x in changed:
     if mp[x] == 0 -> continue (already used as a double of a smaller number)
     if mp[2 * x] == 0 -> return {} (no double found for x)
     ans.push_back(x)
     mp[x]--
     mp[2 * x]--
6. Return ans.
*/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0) return {};

        sort(changed.begin(), changed.end());

        unordered_map<int, int> mp;
        for (int x : changed) {
            mp[x]++;
        }

        vector<int> ans;

        for (int x : changed) {
            // Already consumed as a pair
            if (mp[x] == 0) continue;

            // If the double 2*x is not available
            if (mp[2 * x] == 0) return {};

            ans.push_back(x);
            mp[x]--;
            mp[2 * x]--;
        }

        return ans;
    }
};
