// Link: https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Vector + Hash Map of Index Sets)
// ==========================================
// Time Complexity  : O(1) average for insert, remove, and getRandom
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Data structures:
     vector<int> arr
     unordered_map<int, unordered_set<int>> mp (maps val -> set of indices in arr)
2. insert(val):
     notPresent = (mp[val].empty())
     arr.push_back(val)
     mp[val].insert(arr.size() - 1)
     return notPresent
3. remove(val):
     if mp[val].empty() -> return false
     removeIdx = *mp[val].begin()
     mp[val].erase(removeIdx)
     lastVal = arr.back()
     if removeIdx != arr.size() - 1:
         arr[removeIdx] = lastVal
         mp[lastVal].erase(arr.size() - 1)
         mp[lastVal].insert(removeIdx)
     arr.pop_back()
     return true
4. getRandom():
     return arr[rand() % arr.size()]
*/

class RandomizedCollection {
private:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> mp;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool notPresent = mp[val].empty();

        arr.push_back(val);
        mp[val].insert(arr.size() - 1);

        return notPresent;
    }

    bool remove(int val) {
        if (mp[val].empty()) {
            return false;
        }

        // Get an index where val is located
        int removeIdx = *mp[val].begin();
        mp[val].erase(removeIdx);

        int lastVal = arr.back();
        int lastIdx = arr.size() - 1;

        // Swap with last element if not already at the end
        if (removeIdx != lastIdx) {
            arr[removeIdx] = lastVal;
            mp[lastVal].erase(lastIdx);
            mp[lastVal].insert(removeIdx);
        }

        arr.pop_back();
        return true;
    }

    int getRandom() {
        return arr[rand() % arr.size()];
    }
};
