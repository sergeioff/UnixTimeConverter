#include <stdio.h>
#include <time.h>

using namespace std;

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

int main() {
    printf("%04d/%02d/%02d %02d:%02d:%02d\n", getYear(1425111517), getMonth(1425111517), getDay(1425111517),
           getHours(1425111517), getMinutes(1425111517), getSeconds(1425111517));

    printf("%ld\n", toUnixTime(2015,2,28,10,25,30));

    printf("%04d/%02d/%02d %02d:%02d:%02d\n", getYear(1425111930), getMonth(1425111930), getDay(1425111930),
           getHours(1425111930), getMinutes(1425111930), getSeconds(1425111930));

    return 0;
}


