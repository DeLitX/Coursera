#pragma once
#include "date.h"
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
class Database {
public:
    Database();
    void Add(const Date& date, const string& event);

    template<typename f>
    int RemoveIf(f predicate) {
        int result=0;
        auto previousPtr = events.begin();
        bool isUsePrevious = false;
        bool isFirst = true;
        for (auto t = events.begin(); t != events.end();) {
            for (int i = 0; i < t->second.first.size();i++) {
                if (predicate(t->first, t->second.first[i])) {
                    t->second.second.erase(t->second.first[i]);
                    t->second.first.erase(t->second.first.begin()+i);
                    result++;
                    if (t->second.second.size() == 0) {
                        allDates.erase(t->first);
                        events.erase(t);
                        isUsePrevious = true;
                        break;
                    }
                    i--;
                }
            }
            if (isUsePrevious) {
                if (isFirst) {
                    t = events.begin();
                    previousPtr = events.begin();
                }
                else {
                    t = previousPtr;
                    t++;
                }
                isUsePrevious = false;
            }
            else {
                previousPtr = t;
                isFirst = false;
                t++;
            }
        }
        return result;
    }
    template<typename f>
    vector<pair<Date, string>> FindIf(f predicate) const {
        vector<pair<Date, string>> result;
        for (const auto& a : events) {
            for (const auto& event : a.second.first) {
                if (predicate(a.first, event)) {
                    result.push_back(make_pair(a.first, event));
                }
            }
        }
        return result;
    }

    string Last(const Date& date) const;
    void Print(ostream& s) const;
private:
    map<Date,pair<vector<string>,set<string>>> events;
    set<Date>allDates;
};