// Link: https://leetcode.com/problems/next-greater-element-i/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Monotonic Stack + Hash Map)
// ==========================================
// Time Complexity  : O(n1 + n2)
// Space Complexity : O(n2)
/*
PSEUDOCODE:
1. Create hash map nextGreater: element -> next_greater_element.
2. Initialize stack<int> st.
3. For each x in nums2:
     While !st.empty() && x > st.top():
         nextGreater[st.top()] = x
         st.pop()
     st.push(x)
4. For each x in nums1:
     ans.push_back(nextGreater.count(x) ? nextGreater[x] : -1)
5. Return ans.
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        // Find next greater for every element in nums2
        for (int x : nums2) {
            while (!st.empty() && x > st.top()) {
                nextGreater[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }

        vector<int> ans;
        for (int x : nums1) {
            if (nextGreater.find(x) != nextGreater.end()) {
                ans.push_back(nextGreater[x]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
