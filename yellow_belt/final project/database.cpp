#include "database.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
Database::Database(){}
void Database::Add(const Date& date, const string& event) {
    if (events[date].second.find(event) == events[date].second.end()) {
        events.at(date).first.push_back(event);
        events.at(date).second.insert(event);
        allDates.insert(date);
    }
}

string Database::Last(const Date& date) const{
    Date a=date;
    auto b = allDates.upper_bound(date);
    if (b == allDates.begin()) {
        return "No entries";
    }
    a = *prev(b);
    stringstream is;
    is.fill('0');
    is << a << " " <<  events.at(a).first[events.at(a).first.size()-1];
    string result;
    getline(is, result);
    return result;
}

void Database::Print(ostream& s) const {
    for (auto a : events) {
        //sort(a.second.begin(), a.second.end());
        for (auto b : a.second.first) {
            s << a.first << " " << b << endl;
        }
    }
}