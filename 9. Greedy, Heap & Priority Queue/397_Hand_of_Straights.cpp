// Link: https://leetcode.com/problems/hand-of-straights/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Ordered Map Frequency Deduction)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. If hand.size() % groupSize != 0 return false.
2. Count card frequencies in map<int, int> freq (ordered).
3. For each [card, count] in freq:
     if count > 0:
         For i from 1 to groupSize - 1:
             if freq[card + i] < count return false
             freq[card + i] -= count
4. Return true.
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        for (auto& p : freq) {
            int card = p.first;
            int count = p.second;

            if (count > 0) {
                for (int i = 1; i < groupSize; i++) {
                    if (freq[card + i] < count) {
                        return false;
                    }
                    freq[card + i] -= count;
                }
            }
        }

        return true;
    }
};
