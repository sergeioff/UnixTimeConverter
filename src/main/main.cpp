#include "mytimefunctions.h"
#include <stdio.h>

using namespace std;

int main() {
	long timestamp = 1425323785;

	int year, month, day, hours, minutes, seconds;

	printf("%ld -> %04d/%02d/%02d %02d:%02d:%02d\n", timestamp, year = getYear(timestamp), month = getMonth(timestamp), 
		day = getDay(timestamp), hours = getHours(timestamp), minutes = getMinutes(timestamp), seconds = getSeconds(timestamp));

	printf("%04d/%02d/%02d %02d:%02d:%02d -> %ld\n", year, month, day, hours, minutes, seconds, 
		toUnixTime(year, month, day, hours, minutes, seconds));
}
