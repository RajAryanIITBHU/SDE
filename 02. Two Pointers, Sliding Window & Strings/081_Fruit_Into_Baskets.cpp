// Link: https://leetcode.com/problems/fruit-into-baskets/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sliding Window: At Most 2 Distinct Elements)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) (map size at most 3)
/*
PSEUDOCODE:
1. Create hash map mp: fruitType -> count.
2. Initialize left = 0, ans = 0.
3. For right from 0 to n-1:
     mp[fruits[right]]++
     While mp.size() > 2:
         mp[fruits[left]]--
         if mp[fruits[left]] == 0:
             mp.erase(fruits[left])
         left++
     ans = max(ans, right - left + 1)
4. Return ans.
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> mp; // {fruitType, count}

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            mp[fruits[right]]++;

            // Shrink window if more than 2 distinct fruit types
            while (mp.size() > 2) {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
