// Link: https://leetcode.com/problems/reverse-string/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Two Pointers In-Place Swap)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) in-place
/*
PSEUDOCODE:
1. Initialize left = 0, right = n - 1.
2. While left < right:
     swap(s[left], s[right])
     left++
     right--
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = (int)s.size() - 1;

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
