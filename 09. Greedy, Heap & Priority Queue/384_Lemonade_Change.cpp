// Link: https://leetcode.com/problems/lemonade-change/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Bill Tracking)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. five = 0, ten = 0.
2. For each bill in bills:
     if bill == 5: five++
     else if bill == 10:
         if five == 0 return false
         five--, ten++
     else (bill == 20):
         // Prefer giving one 10 and one 5 over three 5s
         if ten > 0 && five > 0:
             ten--, five--
         else if five >= 3:
             five -= 3
         else:
             return false
3. Return true.
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else { // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
