// Link: https://leetcode.com/problems/design-parking-system/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Slot Count Array)
// ==========================================
// Time Complexity  : Constructor: O(1), addCar: O(1)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Maintain slots array of size 4: slots[1] = big, slots[2] = medium, slots[3] = small.
2. addCar(carType):
     if slots[carType] > 0:
         slots[carType]--
         return true
     return false
*/

class ParkingSystem {
private:
    int slots[4];

public:
    ParkingSystem(int big, int medium, int small) {
        slots[1] = big;
        slots[2] = medium;
        slots[3] = small;
    }

    bool addCar(int carType) {
        if (slots[carType] > 0) {
            slots[carType]--;
            return true;
        }
        return false;
    }
};
