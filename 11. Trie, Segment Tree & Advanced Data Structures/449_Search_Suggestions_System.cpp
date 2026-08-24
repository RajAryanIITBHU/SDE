// Link: https://leetcode.com/problems/search-suggestions-system/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sorting + Binary Search Two Pointers)
// ==========================================
// Time Complexity  : O(N log N + L * log N), where N is products count, L is searchWord length
// Space Complexity : O(1) auxiliary
/*
PSEUDOCODE:
1. Sort products lexicographically in ascending order.
2. left = 0, right = products.size() - 1, vector<vector<string>> ans.
3. For i from 0 to searchWord.length() - 1:
     char c = searchWord[i]
     While left <= right && (products[left].length() <= i || products[left][i] != c):
         left++
     While left <= right && (products[right].length() <= i || products[right][i] != c):
         right--
     Take at most 3 words from left to min(left + 3, right + 1) and append to ans.
4. Return ans.
*/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        int left = 0;
        int right = (int)products.size() - 1;
        vector<vector<string>> ans;

        for (int i = 0; i < (int)searchWord.length(); i++) {
            char c = searchWord[i];

            // Narrow left pointer to match prefix at index i
            while (left <= right && (products[left].length() <= i || products[left][i] != c)) {
                left++;
            }

            // Narrow right pointer to match prefix at index i
            while (left <= right && (products[right].length() <= i || products[right][i] != c)) {
                right--;
            }

            // Collect up to 3 suggested products
            vector<string> suggestions;
            for (int j = left; j <= min(left + 2, right); j++) {
                suggestions.push_back(products[j]);
            }

            ans.push_back(suggestions);
        }

        return ans;
    }
};
