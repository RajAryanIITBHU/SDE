// Link: https://leetcode.com/problems/plus-one/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE / EXTRA SPACE (Carry Simulation)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n) auxiliary space
/*
PSEUDOCODE:
1. Initialize carry = 1 and an empty vector ans.
2. Traverse digits from right to left (i = n-1 down to 0):
     sum = digits[i] + carry
     ans.push_back(sum % 10)
     carry = sum / 10
3. If carry > 0, push carry to ans.
4. Reverse ans to get correct most-significant-first order.
5. Return ans.
*/

class SolutionBruteForce {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        int carry = 1;

        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
        }

        if (carry > 0) {
            ans.push_back(carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (In-place Traversal)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) auxiliary space (modifies input in-place)
/*
PSEUDOCODE:
1. Traverse digits from right to left (i = n-1 down to 0):
     a. If digits[i] < 9:
          digits[i]++
          return digits (no further carry propagation needed)
     b. Else (digits[i] == 9):
          digits[i] = 0
2. If loop finishes, all digits were 9 (e.g., 999 -> 000):
     Insert 1 at the beginning of digits.
3. Return digits.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse backwards from last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; // Early return as carry stops here
            }

            // If digit is 9, it becomes 0 and carry continues
            digits[i] = 0;
        }

        // If all digits were 9 (e.g. 99 -> 100)
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
