// Link: https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Exact K = At Most K - At Most (K - 1))
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) (26 characters)
/*
PSEUDOCODE:
Count substrings with exactly k distinct characters = atMostK(s, k) - atMostK(s, k - 1).
1. Helper atMostK(s, k):
     if k <= 0 return 0
     freq array of size 26, distinctCount = 0, left = 0, count = 0
     For right from 0 to s.length() - 1:
         if freq[s[right] - 'a'] == 0: distinctCount++
         freq[s[right] - 'a']++
         While distinctCount > k:
             freq[s[left] - 'a']--
             if freq[s[left] - 'a'] == 0: distinctCount--
             left++
         count += (right - left + 1)
     return count
2. Return atMostK(s, k) - atMostK(s, k - 1).
*/

class Solution {
private:
    long long int atMostK(const string& s, int k) {
        if (k <= 0) return 0;

        vector<int> freq(26, 0);
        int distinct = 0;
        int left = 0;
        long long int count = 0;

        for (int right = 0; right < (int)s.length(); right++) {
            if (freq[s[right] - 'a'] == 0) {
                distinct++;
            }
            freq[s[right] - 'a']++;

            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0) {
                    distinct--;
                }
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

public:
    long long int substrCount(string s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};
