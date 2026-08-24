// Link: https://www.interviewbit.com/problems/subarray-with-given-xor/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Prefix XOR with Frequency Hash Map)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
If current prefix XOR is X, we need a prefix XOR Y such that X ^ Y = B, which implies Y = X ^ B.
1. xr = 0, count = 0.
2. freq map: freq[0] = 1.
3. For each num in arr:
     xr ^= num
     need = xr ^ B
     if freq.count(need):
         count += freq[need]
     freq[xr]++
4. Return count.
*/

class Solution {
public:
    int solve(vector<int>& arr, int B) {
        unordered_map<int, int> freq;
        freq[0] = 1; // Empty prefix

        int xr = 0;
        int count = 0;

        for (int num : arr) {
            xr ^= num;
            int need = xr ^ B;

            if (freq.find(need) != freq.end()) {
                count += freq[need];
            }

            freq[xr]++;
        }

        return count;
    }
};
