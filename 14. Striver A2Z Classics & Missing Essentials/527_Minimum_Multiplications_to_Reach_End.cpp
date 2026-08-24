// Link: https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (BFS Shortest Path on Modulo 100,000 Graph)
// ==========================================
// Time Complexity  : O(100000 * n)
// Space Complexity : O(100000)
/*
PSEUDOCODE:
1. dist array of size 100000 initialized to 1e9.
2. dist[start] = 0, queue q.push({start, 0 steps}).
3. While !q.empty():
     {node, steps} = q.front(), q.pop()
     if node == end return steps
     For num in arr:
         nextVal = (node * num) % 100000
         if steps + 1 < dist[nextVal]:
             dist[nextVal] = steps + 1
             q.push({nextVal, steps + 1})
4. Return -1.
*/

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if (start == end) return 0;

        const int MOD = 100000;
        vector<int> dist(MOD, 1e9);
        queue<pair<int, int>> q; // {nodeValue, steps}

        dist[start] = 0;
        q.push({start, 0});

        while (!q.empty()) {
            auto [node, steps] = q.front();
            q.pop();

            for (int num : arr) {
                int nextVal = (1LL * node * num) % MOD;

                if (steps + 1 < dist[nextVal]) {
                    dist[nextVal] = steps + 1;
                    if (nextVal == end) {
                        return steps + 1;
                    }
                    q.push({nextVal, steps + 1});
                }
            }
        }

        return -1;
    }
};
