// Link: https://leetcode.com/problems/split-array-into-consecutive-subsequences/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Frequency & Vacancy Hash Maps)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Count frequencies in freq map.
2. need map: need[x] = number of existing subsequences that need x next.
3. For each num in nums:
     if freq[num] == 0 continue
     if need[num] > 0: // Append to existing consecutive subsequence
         need[num]--
         need[num + 1]++
     else if freq[num + 1] > 0 && freq[num + 2] > 0: // Start new sequence of length 3
         freq[num + 1]--
         freq[num + 2]--
         need[num + 3]++
     else:
         return false
     freq[num]--
4. Return true.
*/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> need;

        for (int num : nums) {
            freq[num]++;
        }

        for (int num : nums) {
            if (freq[num] == 0) continue;

            // Option 1: Append to existing sequence
            if (need[num] > 0) {
                need[num]--;
                need[num + 1]++;
            }
            // Option 2: Start new sequence of 3 elements: num, num+1, num+2
            else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                freq[num + 1]--;
                freq[num + 2]--;
                need[num + 3]++;
            } else {
                return false;
            }

            freq[num]--;
        }

        return true;
    }
};
