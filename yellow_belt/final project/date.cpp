#include "date.h"
#include <sstream>
#include <vector>
#include<iomanip>
using namespace std;
ostream& operator<<(ostream& os, const Date& date) {
    os.fill('0');
    os << setw(4) << date.GetYear() << "-" << setw(2) << date.GetMonth() << "-" << setw(2) << date.GetDay();
    return os;
}
bool operator<(const Date& lhs, const Date& rhs) {
    return lhs.GetDay() + lhs.GetMonth() * 31 + lhs.GetYear() * 31 * 12 <
        rhs.GetDay() + rhs.GetMonth() * 31 + rhs.GetYear() * 31 * 12;
}
bool operator<=(const Date& lhs, const Date& rhs) {
    return lhs.GetDay() + lhs.GetMonth() * 31 + lhs.GetYear() * 31 * 12 <=
        rhs.GetDay() + rhs.GetMonth() * 31 + rhs.GetYear() * 31 * 12;
}
bool operator==(const Date& lhs, const Date& rhs) {
    return lhs.GetDay() + lhs.GetMonth() * 31 + lhs.GetYear() * 31 * 12 ==
        rhs.GetDay() + rhs.GetMonth() * 31 + rhs.GetYear() * 31 * 12;
}
bool operator!=(const Date& lhs, const Date& rhs) {
    return lhs.GetDay() + lhs.GetMonth() * 31 + lhs.GetYear() * 31 * 12 !=
        rhs.GetDay() + rhs.GetMonth() * 31 + rhs.GetYear() * 31 * 12;
}
bool operator>=(const Date& lhs, const Date& rhs) {
    return lhs.GetDay() + lhs.GetMonth() * 31 + lhs.GetYear() * 31 * 12 >=
        rhs.GetDay() + rhs.GetMonth() * 31 + rhs.GetYear() * 31 * 12;
}
bool operator>(const Date& lhs, const Date& rhs) {
    return lhs.GetDay() + lhs.GetMonth() * 31 + lhs.GetYear() * 31 * 12 >
        rhs.GetDay() + rhs.GetMonth() * 31 + rhs.GetYear() * 31 * 12;
}
Date::Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}
int Date::GetYear() const {
    return year;
}
int Date::GetMonth() const {
    return month;
}
int Date::GetDay() const {
    return day;
}
Date ParseDate(istream& iss) {
    int year = 0, month = 0, day = 0;
    char dash = '-';
    iss >> year >> dash >> month >> dash >> day;
    return { year, month, day };
    /*string a;
    int year, month, day;
    char defis, defis1;
    vector<string> b;
    bool addMinus = false;
    while (iss) {
        string temp;
        getline(iss, temp, '-');
        a += temp;
        if (addMinus) {
            temp = "-" + temp;
            addMinus = false;
        }
        if (temp[0] == '+') {
            temp.erase(temp.begin());
        }
        while (temp.size() > 1 && temp[0] == '0') {
            temp.erase(temp.begin());
        }
        if (temp == "") {
            addMinus = true;
        }
        else {
            b.push_back(temp);
        }
    }
    if (b[b.size() - 1] == "" || b[b.size() - 1] == "\n") {
        b.erase(b.begin() + b.size() - 1);
    }
    if (b.size() != 3) {
        string temp;
        getline(iss, temp);
        cout << "Wrong date format: " << a<<temp << endl;
        throw logic_error("Wrong date format: ");
    }try {
        year = stoi(b[0]);
        month = stoi(b[1]);
        day = stoi(b[2]);
    }
    catch (exception e) {
        string temp;
        getline(iss, temp);
        cout << "Wrong date format: " << a <<temp<< endl;
        throw logic_error("Wrong date format: ");
    }
    if (to_string(year) != b[0] || to_string(month) != b[1] || to_string(day) != b[2]) {
        string temp;
        getline(iss, temp);
        cout << "Wrong date format: " << a <<temp<< endl;
        throw logic_error("Wrong date format: ");
    }
    if (month > 12 || month < 1) {
        cout << "Month value is invalid: " << month << endl;
        throw logic_error("Month value is invalid: ");
    }
    else if (day > 31 || day < 1) {
        cout << "Day value is invalid: " << day << endl;
        throw logic_error("Day value is invalid: ");
    }
    return{ year,month,day };*/
}