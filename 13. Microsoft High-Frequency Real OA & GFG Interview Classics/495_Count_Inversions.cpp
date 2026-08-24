// Link: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Merge Sort Inversion Counting)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Helper mergeSort(left, right, arr, temp):
     if left >= right return 0
     mid = left + (right - left) / 2
     invCount = mergeSort(left, mid, arr, temp) + mergeSort(mid + 1, right, arr, temp)
     i = left, j = mid + 1, k = left
     While i <= mid && j <= right:
         if arr[i] <= arr[j]:
             temp[k++] = arr[i++]
         else:
             temp[k++] = arr[j++]
             invCount += (mid - i + 1) // All remaining elements in left half are inversions
     While i <= mid: temp[k++] = arr[i++]
     While j <= right: temp[k++] = arr[j++]
     Copy temp[left..right] back to arr.
     return invCount
2. Return mergeSort(0, arr.size() - 1, arr, temp).
*/

class Solution {
private:
    long long mergeSort(int left, int right, vector<long long>& arr, vector<long long>& temp) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        long long invCount = 0;

        invCount += mergeSort(left, mid, arr, temp);
        invCount += mergeSort(mid + 1, right, arr, temp);

        int i = left;
        int j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                invCount += (mid - i + 1);
            }
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];

        for (int p = left; p <= right; p++) {
            arr[p] = temp[p];
        }

        return invCount;
    }

public:
    long long int inversionCount(vector<long long>& arr) {
        int n = arr.size();
        vector<long long> temp(n);
        return mergeSort(0, n - 1, arr, temp);
    }
};
