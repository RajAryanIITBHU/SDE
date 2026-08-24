// Link: https://leetcode.com/problems/sliding-window-maximum/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Monotonic Decreasing Deque)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(k) for deque
/*
PSEUDOCODE:
1. Maintain deque<int> dq storing indices in decreasing order of values.
2. For i from 0 to n-1:
     // Remove indices outside the sliding window of size k
     if !dq.empty() && dq.front() <= i - k -> dq.pop_front()
     
     // Remove elements smaller than current element from back
     While !dq.empty() && nums[dq.back()] <= nums[i]:
         dq.pop_back()
     
     dq.push_back(i)
     
     // Record window maximum
     if i >= k - 1 -> ans.push_back(nums[dq.front()])
3. Return ans.
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq; // Stores indices
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            // Remove elements out of current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Maintain monotonic decreasing order
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // The largest element in current window is at dq.front()
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
