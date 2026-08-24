// Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Fixed Sliding Window + Frequency Arrays)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) (fixed 26-size arrays)
/*
PSEUDOCODE:
1. If s.length() < p.length(), return {}.
2. Create freqP and freqS arrays of size 26.
3. Populate freqP for p and initial window in s.
4. If freqP == freqS -> ans.push_back(0).
5. For i from p.length() to s.length() - 1:
     freqS[s[i] - 'a']++
     freqS[s[i - p.length()] - 'a']--
     if freqP == freqS -> ans.push_back(i - p.length() + 1)
6. Return ans.
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int k = p.length();

        if (n < k) return {};

        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            freqP[p[i] - 'a']++;
            freqS[s[i] - 'a']++;
        }

        if (freqP == freqS) {
            ans.push_back(0);
        }

        // Slide window of fixed length k
        for (int i = k; i < n; i++) {
            freqS[s[i] - 'a']++;
            freqS[s[i - k] - 'a']--;

            if (freqP == freqS) {
                ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};
