// Link: https://leetcode.com/problems/water-and-jug-problem/

#include <iostream>
#include <numeric>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Bézout's Identity & GCD)
// ==========================================
// Time Complexity  : O(log(min(x, y)))
// Space Complexity : O(1)
/*
PSEUDOCODE:
By Bézout's Identity:
Any measurable water amount must be a linear combination: a*x + b*y = target.
Thus, target must be divisible by gcd(x, y) and target <= x + y.
1. If target > x + y return false.
2. If target == 0 return true.
3. Return target % gcd(x, y) == 0.
*/

class Solution {
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false;
        if (target == 0) return true;

        return target % gcd(x, y) == 0;
    }
};
