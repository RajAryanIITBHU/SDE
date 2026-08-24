// Link: https://leetcode.com/problems/paint-fence/

#include <iostream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Space-Optimized DP - Same & Diff States)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If n == 0 return 0.
2. If n == 1 return k.
3. same = k, diff = k * (k - 1).
4. For i from 3 to n:
     prevDiff = diff
     diff = (same + diff) * (k - 1)
     same = prevDiff
5. Return same + diff.
*/

class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;

        int same = k;               // Posts 1 and 2 same color
        int diff = k * (k - 1);     // Posts 1 and 2 diff color

        for (int i = 3; i <= n; i++) {
            int prevDiff = diff;
            diff = (same + diff) * (k - 1);
            same = prevDiff;
        }

        return same + diff;
    }
};
