// Link: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Math Formulation: Sum & Sum of Squares)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
Let R = repeating, M = missing.
  diff = sum(arr) - sum(1..n) = R - M
  sqDiff = sum(arr^2) - sum((1..n)^2) = R^2 - M^2 = (R - M)(R + M)
  sumRM = sqDiff / diff = R + M
  R = (diff + sumRM) / 2
  M = sumRM - R
1. Return {R, M}.
*/

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();

        long long sumN = (n * (n + 1)) / 2;
        long long sumSqN = (n * (n + 1) * (2 * n + 1)) / 6;

        long long actualSum = 0;
        long long actualSumSq = 0;

        for (long long x : arr) {
            actualSum += x;
            actualSumSq += (x * x);
        }

        long long diff = actualSum - sumN;           // R - M
        long long sqDiff = actualSumSq - sumSqN;     // R^2 - M^2

        long long sumRM = sqDiff / diff;             // R + M

        long long repeating = (diff + sumRM) / 2;
        long long missing = sumRM - repeating;

        return {(int)repeating, (int)missing};
    }
};
