// Link: https://leetcode.com/problems/next-greater-element-iv/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Two Monotonic Stacks: st1 and st2)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize ans array of size n with -1.
2. st1: stack for elements waiting for their 1st next greater element.
3. st2: stack for elements that already found their 1st next greater, waiting for their 2nd next greater element.
4. For each element nums[i]:
     // Elements in st2 found their 2nd next greater (nums[i])
     While !st2.empty() && nums[st2.top()] < nums[i]:
         ans[st2.top()] = nums[i]
         st2.pop()
     
     // Elements in st1 found their 1st next greater (nums[i]), transfer to st2
     vector<int> temp;
     While !st1.empty() && nums[st1.top()] < nums[i]:
         temp.push_back(st1.top())
         st1.pop()
     While !temp.empty():
         st2.push(temp.back())
         temp.pop_back()
     
     st1.push(i)
5. Return ans.
*/

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        vector<int> st1; // Waiting for 1st greater element
        vector<int> st2; // Waiting for 2nd greater element

        for (int i = 0; i < n; i++) {
            // Find 2nd next greater for elements in st2
            while (!st2.empty() && nums[st2.back()] < nums[i]) {
                ans[st2.back()] = nums[i];
                st2.pop_back();
            }

            // Elements in st1 that found their 1st greater element move into temp
            vector<int> temp;
            while (!st1.empty() && nums[st1.back()] < nums[i]) {
                temp.push_back(st1.back());
                st1.pop_back();
            }

            // Push into st2 preserving decreasing order
            while (!temp.empty()) {
                st2.push_back(temp.back());
                temp.pop_back();
            }

            st1.push_back(i);
        }

        return ans;
    }
};
