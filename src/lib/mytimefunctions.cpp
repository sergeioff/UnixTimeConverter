#include "mytimefunctions.h"
#include <time.h>

int getYear(long timestamp) {
    return 1900 + localtime(&timestamp)->tm_year;
}

int getMonth(long timestamp) {
    return ++localtime(&timestamp)->tm_mon;
}

int getDay(long timestamp) {
    return localtime(&timestamp)->tm_mday;
}

int getHours(long timestamp) {
    return localtime(&timestamp)->tm_hour;
}

int getMinutes(long timestamp) {
    return localtime(&timestamp)->tm_min;
}

int getSeconds(long timestamp) {
    return localtime(&timestamp)->tm_sec;
}

long toUnixTime(int year, int month, int day, int hours, int minutes, int seconds) {
    struct tm * time = new tm;

    time->tm_year = year - 1900;
    time->tm_mon = month - 1;
    time->tm_mday = day;
    time->tm_hour = hours;
    time->tm_min = minutes;
    time->tm_sec = seconds;

    return mktime(time);
}
