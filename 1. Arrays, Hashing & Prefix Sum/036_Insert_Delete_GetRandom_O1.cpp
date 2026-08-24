// Link: https://leetcode.com/problems/insert-delete-getrandom-o1/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Dynamic Array + Hash Map)
// ==========================================
// Time Complexity  : O(1) average for insert, remove, and getRandom
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Data structures:
     vector<int> arr (stores the values)
     unordered_map<int, int> mp (maps value -> index in arr)
2. insert(val):
     if mp.count(val) -> return false
     arr.push_back(val)
     mp[val] = arr.size() - 1
     return true
3. remove(val):
     if !mp.count(val) -> return false
     idx = mp[val]
     lastVal = arr.back()
     arr[idx] = lastVal
     mp[lastVal] = idx
     arr.pop_back()
     mp.erase(val)
     return true
4. getRandom():
     return arr[rand() % arr.size()]
*/

class RandomizedSet {
private:
    vector<int> arr;
    unordered_map<int, int> mp; // {value, index in arr}

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false;
        }

        arr.push_back(val);
        mp[val] = arr.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }

        // Swap target element with last element to achieve O(1) deletion
        int idx = mp[val];
        int lastVal = arr.back();

        arr[idx] = lastVal;
        mp[lastVal] = idx;

        arr.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {
        int randomIdx = rand() % arr.size();
        return arr[randomIdx];
    }
};
