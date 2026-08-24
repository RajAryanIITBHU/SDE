// Link: https://leetcode.com/problems/top-k-frequent-elements/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Frequency Map + Full Sort)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Count frequencies using hash map mp.
2. Put all pairs {frequency, element} into an array arr.
3. Sort arr in descending order.
4. Pick first k elements from arr and return.
*/

class SolutionBruteForce {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }

        vector<pair<int, int>> arr; // {frequency, element}
        for (auto& it : mp) {
            arr.push_back({it.second, it.first});
        }

        sort(arr.rbegin(), arr.rend());

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i].second);
        }

        return ans;
    }
};

// ==========================================
// 2. BETTER APPROACH (Min-Heap of Size K)
// ==========================================
// Time Complexity  : O(n log k)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Count frequencies using hash map mp.
2. Maintain a min-heap pq of size k storing {frequency, element}.
3. For each pair in mp:
     pq.push({frequency, element})
     if pq.size() > k -> pq.pop()
4. Extract all elements from heap into ans.
5. Return ans.
*/

class SolutionBetter {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }

        // Min-heap to keep top k elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto& it : mp) {
            pq.push({it.second, it.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Bucket Sort)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Count frequencies using hash map mp.
2. Create buckets of size n + 1 where buckets[freq] stores elements with that frequency.
3. Traverse buckets from index n down to 1:
     Add elements to ans until ans.size() == k.
4. Return ans.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        // Frequency buckets: index is frequency, value is list of elements
        vector<vector<int>> buckets(n + 1);
        for (auto& it : mp) {
            buckets[it.second].push_back(it.first);
        }

        vector<int> ans;
        for (int freq = n; freq >= 1 && ans.size() < k; freq--) {
            for (int val : buckets[freq]) {
                ans.push_back(val);
                if (ans.size() == k) break;
            }
        }

        return ans;
    }
};
