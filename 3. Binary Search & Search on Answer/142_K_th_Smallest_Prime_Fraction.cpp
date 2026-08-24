// Link: https://leetcode.com/problems/k-th-smallest-prime-fraction/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Fraction Value + Two Pointers)
// ==========================================
// Time Complexity  : O(n * log(accuracy))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Search range for fraction value: low = 0.0, high = 1.0.
2. While low < high:
     mid = (low + high) / 2.0
     Count fractions <= mid and track maximum fraction <= mid (bestNum / bestDen).
     j = 1, count = 0
     For i from 0 to n-1:
         While j < n && arr[i] > mid * arr[j]:
             j++
         count += (n - j)
         if j < n && arr[i] * bestDen > bestNum * arr[j]:
             bestNum = arr[i], bestDen = arr[j]
     if count == k -> return {bestNum, bestDen}
     else if count < k -> low = mid
     else -> high = mid
*/

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double low = 0.0, high = 1.0;

        while (low < high) {
            double mid = (low + high) / 2.0;

            int count = 0;
            int bestNum = 0, bestDen = 1;
            int j = 1;

            for (int i = 0; i < n; i++) {
                while (j < n && arr[i] > mid * arr[j]) {
                    j++;
                }

                count += (n - j);

                // Track the largest fraction <= mid found in this iteration
                if (j < n && arr[i] * bestDen > bestNum * arr[j]) {
                    bestNum = arr[i];
                    bestDen = arr[j];
                }
            }

            if (count == k) {
                return {bestNum, bestDen};
            } else if (count < k) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return {};
    }
};
