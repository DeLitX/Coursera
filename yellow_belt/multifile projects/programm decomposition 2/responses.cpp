#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (r.stop == "") {
        os << "No stop";
    }
    else {
        bool isFirst = true;
        for (auto i : r.buses) {
            if (isFirst) {
                os << i;
                isFirst = false;
            }
            else {
                os << " " << i;
            }
        }
    }
    return os;
}



ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (r.stops.size() == 0) {
        os << "No bus";
    }
    else {
        for (auto i : r.stops) {
            os << "Stop " << i.first << ":";
            if (i.second.size() > 1) {
                for (auto t : i.second) {
                    if (t != r.bus) {
                        os << " " << t;
                    }
                }
            }
            else {
                os << " no interchange";
            }
            os << endl;
        }
    }

    return os;
}



ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.bus_to_stops.size() == 0) {
        os << "No buses";
    }
    else {
        for (auto i : r.bus_to_stops) {
            os << "Bus " << i.first << ":";
            for (auto t : i.second) {
                os << " " << t;
            }
            os << endl;
        }
    }
    return os;
}