// Link: https://leetcode.com/problems/split-array-into-fibonacci-sequence/

#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with Integer Range & Fibonacci Validation)
// ==========================================
// Time Complexity  : O(2^n) bounded by 10 digits per integer
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Helper backtrack(idx, num, currentSeq, ans):
     if idx == num.length() && currentSeq.size() >= 3:
         ans = currentSeq
         return true
     long long val = 0
     For i from idx to num.length() - 1:
         if i > idx && num[idx] == '0' break // No leading zeroes
         val = val * 10 + (num[i] - '0')
         if val > INT_MAX break
         int sz = currentSeq.size()
         if sz >= 2:
             long long sum2 = (long long)currentSeq[sz - 1] + currentSeq[sz - 2]
             if val < sum2 continue
             if val > sum2 break // Cannot match Fibonacci sequence
         currentSeq.push_back(val)
         if backtrack(i + 1, num, currentSeq, ans) return true
         currentSeq.pop_back()
     return false
2. backtrack(0, num, currentSeq, ans).
3. Return ans.
*/

class Solution {
private:
    bool backtrack(int idx, const string& num, vector<int>& currentSeq, vector<int>& ans) {
        if (idx == (int)num.length() && (int)currentSeq.size() >= 3) {
            ans = currentSeq;
            return true;
        }

        long long val = 0;

        for (int i = idx; i < (int)num.length(); i++) {
            // Disallow multi-digit numbers starting with '0'
            if (i > idx && num[idx] == '0') break;

            val = val * 10 + (num[i] - '0');
            if (val > INT_MAX) break;

            int sz = currentSeq.size();
            if (sz >= 2) {
                long long expected = (long long)currentSeq[sz - 1] + currentSeq[sz - 2];
                if (val < expected) continue;
                if (val > expected) break;
            }

            currentSeq.push_back((int)val);
            if (backtrack(i + 1, num, currentSeq, ans)) {
                return true;
            }
            currentSeq.pop_back(); // Backtrack
        }

        return false;
    }

public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> ans;
        vector<int> currentSeq;
        backtrack(0, num, currentSeq, ans);
        return ans;
    }
};
