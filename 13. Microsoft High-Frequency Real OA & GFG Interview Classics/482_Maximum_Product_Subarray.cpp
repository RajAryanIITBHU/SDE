// Link: https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Min & Max Running Product Tracking)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. maxProd = arr[0], minProd = arr[0], ans = arr[0].
2. For i from 1 to n-1:
     if arr[i] < 0: swap(maxProd, minProd)
     maxProd = max((long long)arr[i], maxProd * arr[i])
     minProd = min((long long)arr[i], minProd * arr[i])
     ans = max(ans, maxProd)
3. Return ans.
*/

class Solution {
public:
    long long maxProduct(vector<int>& arr) {
        int n = arr.size();
        long long maxProd = arr[0];
        long long minProd = arr[0];
        long long ans = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] < 0) {
                swap(maxProd, minProd);
            }

            maxProd = max((long long)arr[i], maxProd * arr[i]);
            minProd = min((long long)arr[i], minProd * arr[i]);

            ans = max(ans, maxProd);
        }

        return ans;
    }
};
