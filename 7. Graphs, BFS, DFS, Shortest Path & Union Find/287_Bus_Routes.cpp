// Link: https://leetcode.com/problems/bus-routes/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (BFS on Bus Route Transfer Levels)
// ==========================================
// Time Complexity  : O(total_stops + num_buses^2)
// Space Complexity : O(total_stops + num_buses)
/*
PSEUDOCODE:
1. If source == target return 0.
2. Build map stopToRoutes: stop -> list of busRouteIndices.
3. If source not in stopToRoutes || target not in stopToRoutes return -1.
4. Initialize queue<int> q of bus routes passing through source, visitedRoutes set, visitedStops set.
5. busesTaken = 1.
6. While !q.empty():
     levelSize = q.size()
     For i from 0 to levelSize - 1:
         bus = q.front(), q.pop()
         For each stop in routes[bus]:
             if stop == target return busesTaken
             if stop not in visitedStops:
                 visitedStops.insert(stop)
                 For each nextBus in stopToRoutes[stop]:
                     if nextBus not in visitedRoutes:
                         visitedRoutes.insert(nextBus)
                         q.push(nextBus)
     busesTaken++
7. Return -1.
*/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < (int)routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

        if (stopToRoutes.find(source) == stopToRoutes.end() || stopToRoutes.find(target) == stopToRoutes.end()) {
            return -1;
        }

        unordered_set<int> visRoutes;
        unordered_set<int> visStops;
        queue<int> q;

        for (int bus : stopToRoutes[source]) {
            q.push(bus);
            visRoutes.insert(bus);
        }
        visStops.insert(source);

        int busesTaken = 1;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                int bus = q.front();
                q.pop();

                for (int stop : routes[bus]) {
                    if (stop == target) {
                        return busesTaken;
                    }

                    if (visStops.find(stop) == visStops.end()) {
                        visStops.insert(stop);

                        for (int nextBus : stopToRoutes[stop]) {
                            if (visRoutes.find(nextBus) == visRoutes.end()) {
                                visRoutes.insert(nextBus);
                                q.push(nextBus);
                            }
                        }
                    }
                }
            }

            busesTaken++;
        }

        return -1;
    }
};
