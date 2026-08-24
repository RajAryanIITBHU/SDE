// Link: https://leetcode.com/problems/asteroid-collision/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Vector as Stack Collision Simulation)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize vector<int> st as stack.
2. For each ast in asteroids:
     destroyed = false
     // Collisions occur only when top of stack is moving right (> 0) and current asteroid is moving left (< 0)
     While !st.empty() && st.back() > 0 && ast < 0:
         if abs(ast) > st.back():
             st.pop_back() // Smaller right-moving asteroid destroyed
         else if abs(ast) == st.back():
             st.pop_back() // Both destroyed
             destroyed = true
             break
         else:
             destroyed = true // Current asteroid destroyed
             break
     if !destroyed:
         st.push_back(ast)
3. Return st.
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int ast : asteroids) {
            bool destroyed = false;

            // Collision only happens when top > 0 and incoming ast < 0
            while (!st.empty() && st.back() > 0 && ast < 0) {
                if (abs(ast) > st.back()) {
                    st.pop_back(); // Previous asteroid destroyed, continue checking
                } else if (abs(ast) == st.back()) {
                    st.pop_back(); // Both explode
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // Current asteroid explodes
                    break;
                }
            }

            if (!destroyed) {
                st.push_back(ast);
            }
        }

        return st;
    }
};
