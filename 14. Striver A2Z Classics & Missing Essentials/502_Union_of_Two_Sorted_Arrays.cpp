// Link: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Two Pointers Linear Scan with Deduplication)
// ==========================================
// Time Complexity  : O(n + m)
// Space Complexity : O(1) auxiliary
/*
PSEUDOCODE:
1. i = 0, j = 0, vector<int> ans.
2. Helper append(val): if ans.empty() || ans.back() != val -> ans.push_back(val).
3. While i < n && j < m:
     if arr1[i] <= arr2[j]: append(arr1[i++])
     else: append(arr2[j++])
4. Append remaining from arr1 and arr2.
5. Return ans.
*/

class Solution {
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        vector<int> ans;
        int i = 0, j = 0;

        auto addElement = [&](int val) {
            if (ans.empty() || ans.back() != val) {
                ans.push_back(val);
            }
        };

        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                addElement(arr1[i++]);
            } else {
                addElement(arr2[j++]);
            }
        }

        while (i < n) addElement(arr1[i++]);
        while (j < m) addElement(arr2[j++]);

        return ans;
    }
};
