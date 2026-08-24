// Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Merge Sort with Index Tracking)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Augment nums with original indices: pairs of {value, originalIndex}.
2. Initialize ans array of size n with 0.
3. Helper mergeSort(left, right, pairs, temp, ans):
     if left >= right return
     mid = left + (right - left) / 2
     mergeSort(left, mid, pairs, temp, ans)
     mergeSort(mid + 1, right, pairs, temp, ans)
     Merge both halves:
         i = left, j = mid + 1, k = left, rightCounter = 0
         While i <= mid && j <= right:
             if pairs[j].val < pairs[i].val:
                 rightCounter++
                 temp[k++] = pairs[j++]
             else:
                 ans[pairs[i].idx] += rightCounter
                 temp[k++] = pairs[i++]
         While i <= mid:
             ans[pairs[i].idx] += rightCounter
             temp[k++] = pairs[i++]
         While j <= right: temp[k++] = pairs[j++]
         Copy temp[left..right] back to pairs.
4. Return ans.
*/

class Solution {
private:
    struct Element {
        int val;
        int idx;
    };

    void mergeSort(int left, int right, vector<Element>& pairs, vector<Element>& temp, vector<int>& ans) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(left, mid, pairs, temp, ans);
        mergeSort(mid + 1, right, pairs, temp, ans);

        int i = left;
        int j = mid + 1;
        int k = left;
        int rightCounter = 0;

        while (i <= mid && j <= right) {
            if (pairs[j].val < pairs[i].val) {
                rightCounter++;
                temp[k++] = pairs[j++];
            } else {
                ans[pairs[i].idx] += rightCounter;
                temp[k++] = pairs[i++];
            }
        }

        while (i <= mid) {
            ans[pairs[i].idx] += rightCounter;
            temp[k++] = pairs[i++];
        }

        while (j <= right) {
            temp[k++] = pairs[j++];
        }

        for (int p = left; p <= right; p++) {
            pairs[p] = temp[p];
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<Element> pairs(n);
        vector<Element> temp(n);
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            pairs[i] = {nums[i], i};
        }

        mergeSort(0, n - 1, pairs, temp, ans);
        return ans;
    }
};
