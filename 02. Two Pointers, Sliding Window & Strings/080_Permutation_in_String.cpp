// Link: https://leetcode.com/problems/permutation-in-string/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Fixed Sliding Window + Frequency Arrays)
// ==========================================
// Time Complexity  : O(s2.length())
// Space Complexity : O(1) (fixed 26-size arrays)
/*
PSEUDOCODE:
1. If s1.length() > s2.length() -> return false.
2. Initialize freq1 and freq2 of size 26.
3. Populate freq1 for s1 and initial window in s2.
4. If freq1 == freq2 -> return true.
5. For i from s1.length() to s2.length() - 1:
     freq2[s2[i] - 'a']++
     freq2[s2[i - s1.length()] - 'a']--
     if freq1 == freq2 -> return true
6. Return false.
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        int n = s2.length();

        if (k > n) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (int i = 0; i < k; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        if (freq1 == freq2) return true;

        for (int i = k; i < n; i++) {
            freq2[s2[i] - 'a']++;
            freq2[s2[i - k] - 'a']--;

            if (freq1 == freq2) {
                return true;
            }
        }

        return false;
    }
};
