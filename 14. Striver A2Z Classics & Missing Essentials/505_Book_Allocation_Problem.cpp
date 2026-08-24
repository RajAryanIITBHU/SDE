// Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Answer Space)
// ==========================================
// Time Complexity  : O(n log(sum(arr) - max(arr)))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If students m > books n return -1.
2. Search range: low = max(arr), high = sum(arr).
3. Helper canAllocate(pagesLimit, arr, m):
     studentsCount = 1, pagesAllocated = 0
     For p in arr:
         if pagesAllocated + p > pagesLimit:
             studentsCount++
             pagesAllocated = p
         else:
             pagesAllocated += p
     return studentsCount <= m
4. BS in [low, high]:
     mid = low + (high - low) / 2
     if canAllocate(mid): high = mid - 1
     else: low = mid + 1
5. Return low.
*/

class Solution {
private:
    bool canAllocate(long long pagesLimit, const vector<int>& arr, int m) {
        int students = 1;
        long long currentPages = 0;

        for (int p : arr) {
            if (currentPages + p > pagesLimit) {
                students++;
                currentPages = p;
            } else {
                currentPages += p;
            }
        }

        return students <= m;
    }

public:
    long long findPages(int n, vector<int>& arr, int m) {
        if (m > n) return -1;

        long long low = *max_element(arr.begin(), arr.end());
        long long high = 0;
        for (int x : arr) high += x;

        long long ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canAllocate(mid, arr, m)) {
                ans = mid;
                high = mid - 1; // Try minimizing the maximum pages
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
