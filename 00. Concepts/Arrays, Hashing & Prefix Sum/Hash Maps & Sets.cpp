/*
 * ============================================================================
 * Concept: Hash Maps & Sets (Fast Lookups & Grouping)
 * Subtopic: Arrays, Hashing & Prefix Sum
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Hash Table provides average O(1) time complexity for insertions, deletions, and lookups.
Used for frequency tracking, pair/triplet lookup, deduplication, and grouping (e.g. Group Anagrams).
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: Average O(1) lookup/insert, Worst O(N) on hash collisions.
 * - Space Complexity: O(N) auxiliary space to store elements.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Looking for complement pairs (e.g., Two Sum target - nums[i]).
- Counting frequencies of elements / characters.
- Grouping items by key (Group Anagrams by sorted string key or char count).
- Checking for duplicate elements or set intersection.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Two Sum (LC 1).
2. Group Anagrams (LC 49).
3. Longest Consecutive Sequence (LC 128 - Hash Set for O(1) lookup).
4. Subarray Sum Equals K (Prefix Sum + Hash Map).
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Two Sum
vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int i = 0; i < (int)nums.size(); ++i) {
        int complement = target - nums[i];
        if (mp.count(complement)) return {mp[complement], i};
        mp[nums[i]] = i;
    }
    return {};
}

// Group Anagrams
vector<vector<string>> groupAnagrams(const vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (const string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& pair : mp) result.push_back(pair.second);
    return result;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    auto res = twoSum(nums, 9);
    cout << "Two Sum indices: " << res[0] << ", " << res[1] << "\n";
    return 0;
}
