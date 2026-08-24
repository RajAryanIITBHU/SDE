// Link: https://leetcode.com/problems/task-scheduler/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Math Formula on Max Frequency)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) (26 uppercase letters)
/*
PSEUDOCODE:
1. Count task frequencies. Find maxFreq.
2. Count how many tasks have frequency == maxFreq (countMaxFreq).
3. Minimum idle intervals = (maxFreq - 1) * (n + 1) + countMaxFreq.
4. Return max((int)tasks.size(), (maxFreq - 1) * (n + 1) + countMaxFreq).
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxFreq = 0;

        for (char t : tasks) {
            freq[t - 'A']++;
            maxFreq = max(maxFreq, freq[t - 'A']);
        }

        int countMaxFreq = 0;
        for (int f : freq) {
            if (f == maxFreq) {
                countMaxFreq++;
            }
        }

        int emptySlots = (maxFreq - 1) * (n + 1) + countMaxFreq;
        return max((int)tasks.size(), emptySlots);
    }
};
