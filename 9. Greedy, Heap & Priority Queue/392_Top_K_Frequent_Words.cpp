// Link: https://leetcode.com/problems/top-k-frequent-words/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// Custom comparator for Min-Heap of size K
struct WordCompare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first == b.first) {
            return a.second < b.second; // Alphabetically larger pops first in min-heap
        }
        return a.first > b.first; // Smaller count pops first
    }
};

// ==========================================
// 1. OPTIMAL APPROACH (Min-Heap of Size K with Custom Comparator)
// ==========================================
// Time Complexity  : O(n log k)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Count word frequencies in freq map.
2. Min-heap pq of size k.
3. For each {word, count} in freq:
     pq.push({count, word})
     if pq.size() > k:
         pq.pop()
4. Pop elements from pq and reverse.
5. Return ans.
*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (const string& w : words) {
            freq[w]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, WordCompare> pq;

        for (auto& p : freq) {
            pq.push({p.second, p.first});
            if ((int)pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
