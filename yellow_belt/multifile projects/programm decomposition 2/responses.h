#pragma once
#include <vector>
#include<string>
#include <iostream>
#include<map>
using namespace std;

struct BusesForStopResponse {
    const vector<string> buses;
    const string stop;
};
ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    const vector<pair<string, vector<string>>> stops;
    const string bus;
};
ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    map<string, vector<string>> bus_to_stops;
};
ostream& operator << (ostream& os, const AllBusesResponse& r);