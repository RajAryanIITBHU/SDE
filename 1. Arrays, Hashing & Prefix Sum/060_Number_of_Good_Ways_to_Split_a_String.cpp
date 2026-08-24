// Link: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// ==========================================
// 1. BETTER APPROACH (Prefix & Suffix Distinct Count Arrays)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Build prefixDistinct array where prefixDistinct[i] = unique chars in s[0..i].
2. Build suffixDistinct array where suffixDistinct[i] = unique chars in s[i..n-1].
3. For i from 0 to n-2:
     if prefixDistinct[i] == suffixDistinct[i+1] -> ans++
4. Return ans.
*/

class SolutionBetter {
public:
    int numSplits(string s) {
        int n = s.length();
        vector<int> prefixDistinct(n, 0);
        vector<int> suffixDistinct(n, 0);

        unordered_set<char> stLeft;
        for (int i = 0; i < n; i++) {
            stLeft.insert(s[i]);
            prefixDistinct[i] = stLeft.size();
        }

        unordered_set<char> stRight;
        for (int i = n - 1; i >= 0; i--) {
            stRight.insert(s[i]);
            suffixDistinct[i] = stRight.size();
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (prefixDistinct[i] == suffixDistinct[i + 1]) {
                ans++;
            }
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Two 26-Size Frequency Arrays)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) (fixed 26-size arrays)
/*
PSEUDOCODE:
1. Populate rightFreq array for all characters in s.
2. Initialize rightDistinct = count of distinct chars in rightFreq, leftDistinct = 0.
3. For each char c in s[0..n-2]:
     Transfer c from right to left:
       if leftFreq[c] == 0 -> leftDistinct++
       leftFreq[c]++
       rightFreq[c]--
       if rightFreq[c] == 0 -> rightDistinct--
     if leftDistinct == rightDistinct -> ans++
4. Return ans.
*/

class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        vector<int> leftFreq(26, 0);
        vector<int> rightFreq(26, 0);

        int rightDistinct = 0;
        for (char c : s) {
            if (rightFreq[c - 'a'] == 0) rightDistinct++;
            rightFreq[c - 'a']++;
        }

        int leftDistinct = 0;
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            int c = s[i] - 'a';

            // Add to left
            if (leftFreq[c] == 0) leftDistinct++;
            leftFreq[c]++;

            // Remove from right
            rightFreq[c]--;
            if (rightFreq[c] == 0) rightDistinct--;

            if (leftDistinct == rightDistinct) {
                ans++;
            }
        }

        return ans;
    }
};
