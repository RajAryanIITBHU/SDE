/*
 * ============================================================================
 * Concept: Underground System / Design Classes
 * Subtopic: Microsoft High-Frequency Real OA & GFG Interview Classics
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Real-world system design simulation problem frequently asked in Microsoft OA and technical interview rounds.
Tracks check-ins, check-outs, and calculates average travel times between stations using double hash maps.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(1) per checkIn, checkOut, and getAverageTime operation.
 * - Space Complexity: O(N + S^2) space where S is unique stations, N is active customer check-ins.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Design Underground System (LC 1396).
- Design Parking System (LC 1603).
- Design Hit Counter (LC 362).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Design Underground System (LC 1396).
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkIns; // {id -> {station, time}}
    unordered_map<string, pair<double, int>> routeStats; // {"start-end" -> {totalTime, count}}
public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = checkIns[id];
        checkIns.erase(id);

        string key = startStation + "-" + stationName;
        routeStats[key].first += (t - startTime);
        routeStats[key].second += 1;
    }

    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "-" + endStation;
        auto [totalTime, count] = routeStats[key];
        return totalTime / count;
    }
};

int main() {
    UndergroundSystem sys;
    sys.checkIn(45, "Leyton", 3);
    sys.checkOut(45, "Waterloo", 15);
    cout << "Avg Leyton->Waterloo: " << sys.getAverageTime("Leyton", "Waterloo") << "\n"; // 12.0
    return 0;
}
