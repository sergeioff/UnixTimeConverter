#include <stdio.h>

const int SYEAR = 31536000,
          SDAY = 86400,
          SHOUR = 3600,
          SMINUTE = 60,
          YEAROFFSET = 1970;

const int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int getYearOffset(long timestamp) {
    return timestamp / SYEAR;
}

int getYear(long timestamp) {
    return YEAROFFSET + getYearOffset(timestamp);
}

int getDays(long timestamp) {
    return (timestamp - SYEAR * (getYearOffset(timestamp))) / SDAY;
}

int getLeapDays(int year) {
    int leapDays = 0;
    for (int i = YEAROFFSET; i < year; i++) {
        if ((i % 4) == 0) leapDays++;
    }
    return leapDays;
}

int getMonth(long timestamp) {
    int days = getDays(timestamp) - getLeapDays(getYear(timestamp));

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
    int days = getDays(timestamp) - getLeapDays(getYear(timestamp));

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
    return (timestamp - SYEAR * getYearOffset(timestamp) - SDAY * getDays(timestamp)) / SHOUR;
}

int getMinute(long timestamp) {
    return (timestamp - SYEAR * getYearOffset(timestamp) - SDAY * getDays(timestamp) - SHOUR * getHour(timestamp)) / SMINUTE;
}

int getSecond(long timestamp) {
    return (timestamp - SYEAR * getYearOffset(timestamp) - SDAY * getDays(timestamp) - SHOUR * getHour(timestamp) - SMINUTE * getMinute(timestamp));
}

long toUnixTime(int year, int month, int day, int hour, int minute, int second) {
    int days = --day + getLeapDays(year);
    for (int i = 0; i < month - 1; i++) {
        days += months[i];
    }

    return (year - YEAROFFSET) * SYEAR + days * SDAY + hour * SHOUR + minute * SMINUTE + second;
}

int main() {
    printf("%04i/%02i/%02i %02i:%02i:%02i\n", getYear(1424855329), getMonth(1424855329), getDay(1424855329), getHour(1424855329),
        getMinute(1424855329), getSecond(1424855329));

    printf("%04i/%02i/%02i %02i:%02i:%02i\n", getYear(1000000000), getMonth(1000000000), getDay(1000000000), getHour(1000000000),
        getMinute(1000000000), getSecond(1000000000));

    printf("%04i/%02i/%02i %02i:%02i:%02i\n", getYear(1234567890), getMonth(1234567890), getDay(1234567890), getHour(1234567890),
        getMinute(1234567890), getSecond(1234567890));


    printf("%ld\n", toUnixTime(2015, 2, 25, 11, 34, 30));

    printf("%04i/%02i/%02i %02i:%02i:%02i\n", getYear(1424864070), getMonth(1424864070), getDay(1424864070), getHour(1424864070),
        getMinute(1424864070), getSecond(1424864070));

    return 0;
}


