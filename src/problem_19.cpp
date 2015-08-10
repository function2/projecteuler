// https://projecteuler.net/problem=19
// Michael Seyfert <michael@codesand.org>
/*
Problem Statement:

You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

/*
January - 31
February - 28 or 29
March - 31
April - 30
May - 31
June - 30
July - 31
August - 31
September - 30
October - 31
November - 30
December - 31

1900 mod 4 = 0, however 1900 mod 400 != 0, so 1900 is not a leap year,
1904 is the first leap year.
2000 is the last leap year.
1901 starts on a Tuesday.
The first day of the year increments by one every year, except after leap
years, where it increments by two.
 */

#include<iostream>
using namespace std;

const int NUM_DAYS[12] = {
	31,
	28,//29 on leap years.
	31,
	30,
	31,
	30,
	31,
	31,
	30,
	31,
	30,
	31
};

bool IsLeapYear(int year)
{
	// don't need to worry about centuries for this problem
	return year % 4 == 0;
}

int main()
{
	int num_sundays = 0;
	int curr_day = 2; // Tuesday.
	// We do a simple solution that goes month by month.
	for(int year = 1901; year <= 2000; ++year){
		int last_month = (year != 2000) ? 12 : 11;
		for(int month = 0; month < last_month;++month){
			if(IsLeapYear(year) && month == 1)
				++curr_day;

			curr_day += NUM_DAYS[month];

			// just finished this month, check first day.
			curr_day %= 7;
			if(curr_day % 7 == 0){
				// cout << year << ' ' << (month+2) << '\n';
				++num_sundays;
			}
		}
	}
	cout << num_sundays << '\n';
}
