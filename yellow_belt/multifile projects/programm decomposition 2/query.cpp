#include "query.h"
#include <iostream>
istream& operator >> (istream& is, Query& q) {
    Query query;
    string action;
    is >> action;
    if (action == "NEW_BUS") {
        query.type = QueryType::NewBus;
        is >> query.bus;
        int temp;
        is >> temp;
        for (int i = 0; i < temp; i++) {
            string stop;
            is >> stop;
            query.stops.push_back(stop);
        }
    }
    else if (action == "BUSES_FOR_STOP") {
        query.type = QueryType::BusesForStop;
        is >> query.stop;
    }
    else if (action == "STOPS_FOR_BUS") {
        query.type = QueryType::StopsForBus;
        is >> query.bus;
    }
    else if (action == "ALL_BUSES") {
        query.type = QueryType::AllBuses;
    }
    q = query;
    return is;
}