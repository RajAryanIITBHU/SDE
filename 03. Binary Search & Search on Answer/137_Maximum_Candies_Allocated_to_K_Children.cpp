// Link: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Candies Per Child)
// ==========================================
// Time Complexity  : O(n * log(max(candies)))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper canAllocate(candiesPerChild):
     if candiesPerChild == 0 return true
     childrenServed = 0
     For each c in candies:
         childrenServed += c / candiesPerChild
     return childrenServed >= k
2. Search range: low = 1, high = max(candies), ans = 0.
3. While low <= high:
     mid = low + (high - low) / 2
     if canAllocate(mid):
         ans = mid
         low = mid + 1 // Maximize candies per child
     else:
         high = mid - 1
4. Return ans.
*/

class Solution {
private:
    bool canAllocate(vector<int>& candies, long long k, int candiesPerChild) {
        if (candiesPerChild == 0) return true;

        long long childrenServed = 0;
        for (int c : candies) {
            childrenServed += (c / candiesPerChild);
        }

        return childrenServed >= k;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canAllocate(candies, k, mid)) {
                ans = mid;
                low = mid + 1; // Try allocating more candies
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
