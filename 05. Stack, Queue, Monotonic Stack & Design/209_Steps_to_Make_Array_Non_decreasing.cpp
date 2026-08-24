// Link: https://leetcode.com/problems/steps-to-make-array-non-decreasing/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Monotonic Stack of Steps)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize ans = 0.
2. Maintain stack<pair<int, int>> st storing {value, stepsNeededToEat} traversing from right to left.
3. For i from n - 1 down to 0:
     steps = 0
     While !st.empty() && nums[i] > st.top().first:
         steps = max(steps + 1, st.top().second)
         st.pop()
     ans = max(ans, steps)
     st.push({nums[i], steps})
4. Return ans.
*/

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int, int>> st; // {value, stepsTakenToEraseDescendants}
        int ans = 0;

        // Traverse right to left
        for (int i = n - 1; i >= 0; i--) {
            int steps = 0;

            // Current element nums[i] can eat elements to its right smaller than itself
            while (!st.empty() && nums[i] > st.top().first) {
                steps = max(steps + 1, st.top().second);
                st.pop();
            }

            ans = max(ans, steps);
            st.push({nums[i], steps});
        }

        return ans;
    }
};
