// Link: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Remainder Frequency Array)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(k)
/*
PSEUDOCODE:
1. Create frequency array remCount of size k initialized to 0.
2. For each x in arr:
     rem = (x % k + k) % k // normalize negative numbers
     remCount[rem]++
3. Remainder 0 elements must be even in count:
     if remCount[0] % 2 != 0 -> return false
4. For rem from 1 to k/2:
     if remCount[rem] != remCount[k - rem] -> return false
5. If k is even:
     if remCount[k / 2] % 2 != 0 -> return false
6. Return true.
*/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remCount(k, 0);

        for (int x : arr) {
            int rem = (x % k + k) % k;
            remCount[rem]++;
        }

        // Remainder 0 elements must pair with each other
        if (remCount[0] % 2 != 0) {
            return false;
        }

        // Remainder r must pair with (k - r)
        for (int r = 1; r <= k / 2; r++) {
            if (r == k - r) {
                // If r == k/2, must have even count
                if (remCount[r] % 2 != 0) return false;
            } else {
                if (remCount[r] != remCount[k - r]) return false;
            }
        }

        return true;
    }
};
