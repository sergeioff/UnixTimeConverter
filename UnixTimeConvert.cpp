#include "iostream"

int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int getYearOffset(long timestamp) {
    return timestamp / 31536000;
}

int getYear(long timestamp) {
    return 1970 + getYearOffset(timestamp);
}

int getDays(long timestamp) {
    return (timestamp - 31536000 * (getYearOffset(timestamp))) / 86400;
}

int getVysDays(int year) {
    int vys = 0;
    for (int i = 1970; i < year; i++) {
        if ((i % 4) == 0) vys++;
    }
    return vys;
}

int getMonth(long timestamp) {
    int days = ((timestamp - 31536000 * getYearOffset(timestamp)) / 86400) - getVysDays(getYear(timestamp));

    int month = 0;
    while (days - months[month] >= 1) {
        if ((month == 1) && ((getYear(timestamp) % 4) == 0)) {
            days -= 29;
        } else {
            days -= months[month++];
        }
    }

    return ++month;
}

int getDay(long timestamp) {

    int days = getDays(timestamp) - getVysDays(getYear(timestamp));

    for (int i = 0; i < getMonth(timestamp) - 1; i++) {
        if ((i == 1) && ((getYear(timestamp) % 4) == 0)) {
            days -= 29;
        } else {
            days -= months[i];
        }
    }

    return ++days;
}

int getHour(long timestamp) {
    return (timestamp - 31536000 * getYearOffset(timestamp) - 86400 * getDays(timestamp)) / 3600;
}

int getMinute(long timestamp) {
    return (timestamp - 31536000 * getYearOffset(timestamp) - 86400 * getDays(timestamp) - 3600 * getHour(timestamp)) / 60;
}

int getSecond(long timestamp) {
    return (timestamp - 31536000 * getYearOffset(timestamp) - 86400 * getDays(timestamp) - 3600 * getHour(timestamp) - 60 * getMinute(timestamp));
}

long toUnixTime(int year, int month, int day, int hour, int minute, int second) {
    int days = --day + getVysDays(year);
    for (int i = 0; i < month - 1; i++) {
        days += months[i];
    }

    return (year - 1970) * 31536000 + days * 86400 + hour * 3600 + minute * 60 + second;
}

int main() {
    using namespace std;

    cout << getYear(1424855329) << "/" << getMonth(1424855329) << "/" << getDay(1424855329) << " "
         << getHour(1424855329) << ":" << getMinute(1424855329) << ":" << getSecond(1424855329) << "\n";

    cout << getYear(1000000000) << "/" << getMonth(1000000000) << "/" << getDay(1000000000) << " "
         << getHour(1000000000) << ":" << getMinute(1000000000) << ":" << getSecond(1000000000) << "\n";

    cout << getYear(1234567890) << "/" << getMonth(1234567890) << "/" << getDay(1234567890) << " "
         << getHour(1234567890) << ":" << getMinute(1234567890) << ":" << getSecond(1234567890) << "\n";

    cout << toUnixTime(2015, 2, 25, 11, 34, 30) << "\n";
    cout << getYear(1424864070) << "/" << getMonth(1424864070) << "/" << getDay(1424864070) << " "
         << getHour(1424864070) << ":" << getMinute(1424864070) << ":" << getSecond(1424864070) << "\n";
    
    return 0;
}


