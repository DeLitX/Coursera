#include "bus_manager.h"
void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    for (auto i : stops) {
        buses_to_stops[i].push_back(bus);
    }
    stops_to_buses[bus] = stops;
}
BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    try {
        return { buses_to_stops.at(stop),stop };
    }
    catch (exception e) {
        return { {},"" };
    }
}
StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    try {
        vector<pair<string, vector<string>>> temp;
        for (auto i : stops_to_buses.at(bus)) {
            temp.push_back({ i,buses_to_stops.at(i) });
        }
        return { temp,bus };
    }
    catch (exception e) {
        return { {},"" };
    }
}
AllBusesResponse BusManager::GetAllBuses() const {
    return { stops_to_buses };
}