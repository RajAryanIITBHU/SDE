// Link: https://leetcode.com/problems/can-place-flowers/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Single Pass Flower Placement)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. For i from 0 to flowerbed.size() - 1:
     if flowerbed[i] == 0:
         emptyLeft = (i == 0 || flowerbed[i - 1] == 0)
         emptyRight = (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)
         if emptyLeft && emptyRight:
             flowerbed[i] = 1
             n--
             if n <= 0 return true
2. Return n <= 0.
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n <= 0) return true;
        int sz = flowerbed.size();

        for (int i = 0; i < sz; i++) {
            if (flowerbed[i] == 0) {
                bool emptyLeft = (i == 0 || flowerbed[i - 1] == 0);
                bool emptyRight = (i == sz - 1 || flowerbed[i + 1] == 0);

                if (emptyLeft && emptyRight) {
                    flowerbed[i] = 1;
                    n--;
                    if (n <= 0) return true;
                }
            }
        }

        return n <= 0;
    }
};
