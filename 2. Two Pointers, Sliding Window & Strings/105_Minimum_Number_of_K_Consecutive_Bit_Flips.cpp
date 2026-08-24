// Link: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sliding Window Flip Tracker / Deque)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(k) (or O(1) in-place modifying nums)
/*
PSEUDOCODE:
1. Maintain currentFlips: number of active flips affecting current index i.
2. Maintain isFlipped or queue storing end indices of flips.
3. For i from 0 to n-1:
     if !q.empty() && q.front() <= i -> q.pop(), currentFlips--
     // Effective bit = (nums[i] + currentFlips) % 2
     if effectiveBit == 0:
         if i + k > n -> return -1 (cannot flip beyond bounds)
         ans++
         currentFlips++
         q.push(i + k)
4. Return ans.
*/

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q; // Stores the end index of each active flip window
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // Remove expired flip effects
            if (!q.empty() && q.front() <= i) {
                q.pop_front();
            }

            // If the number of active flips makes current bit 0
            if ((nums[i] + (int)q.size()) % 2 == 0) {
                // Cannot flip a k-sized window beyond array bounds
                if (i + k > n) {
                    return -1;
                }

                ans++;
                q.push_back(i + k);
            }
        }

        return ans;
    }
};
