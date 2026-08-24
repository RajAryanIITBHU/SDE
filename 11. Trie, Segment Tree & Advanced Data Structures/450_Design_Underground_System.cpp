// Link: https://leetcode.com/problems/design-underground-system/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Check-In Map + Route Statistics Map)
// ==========================================
// Time Complexity  : checkIn, checkOut, getAverageTime: O(1)
// Space Complexity : O(Passengers + Stations^2)
/*
PSEUDOCODE:
1. checkIns map: id -> pair<startStation, checkInTime>.
2. routeStats map: "startStation->endStation" -> pair<totalTravelTime, totalTrips>.
3. checkIn(id, stationName, t): checkIns[id] = {stationName, t}.
4. checkOut(id, stationName, t):
     {startStn, startT} = checkIns[id]
     route = startStn + "->" + stationName
     routeStats[route].totalTime += (t - startT)
     routeStats[route].trips++
     checkIns.erase(id)
5. getAverageTime(startStation, endStation):
     route = startStation + "->" + endStation
     return routeStats[route].totalTime / routeStats[route].trips.
*/

class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkIns; // id -> {stationName, time}
    unordered_map<string, pair<double, int>> routeStats; // "start->end" -> {totalTime, tripCount}

public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto checkInInfo = checkIns[id];
        string startStation = checkInInfo.first;
        int startTime = checkInInfo.second;

        string route = startStation + "->" + stationName;
        routeStats[route].first += (t - startTime);
        routeStats[route].second++;

        checkIns.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "->" + endStation;
        return routeStats[route].first / routeStats[route].second;
    }
};
