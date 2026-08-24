// Link: https://leetcode.com/problems/happy-number/

#include <iostream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Floyd's Cycle-Finding Algorithm)
// ==========================================
// Time Complexity  : O(log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper getNext(n):
     sum = 0
     While n > 0:
         digit = n % 10
         sum += digit * digit
         n /= 10
     return sum
2. slow = n, fast = getNext(n).
3. While fast != 1 && slow != fast:
     slow = getNext(slow)
     fast = getNext(getNext(fast))
4. Return fast == 1.
*/

class Solution {
private:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);

        // Fast & slow pointer cycle detection
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return fast == 1;
    }
};
