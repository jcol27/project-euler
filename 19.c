#include <stdio.h>
#include <math.h>

/*
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

Brute force algorithm.
*/

int main() {
    int day_of_month = 1; // e.g. 15 for the 15th of the month
    int day_week = 0; // Mon = 0, Tues = 1, ..., Sun = 6
    int month = 1; // 1 = Jan etc
    int year = 1900;
    int sundays_count = 0;

    while (!(day_of_month == 31 && month == 12 && year == 2000)) {
        // Check for sunday on first
        if (day_of_month == 1 && day_week == 6 && year >= 1901) {
            sundays_count = sundays_count + 1;
        }

        // Update date

        // If last day of year
        if (day_of_month == 31 && month == 12) {
            day_of_month = 1;
            month = 1;
            year = year + 1;
            day_week = (day_week + 1) % 7;
        }
        // Else if last day of Feb and leap year
        else if (day_of_month == 29 && month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
            day_of_month = 1;
            month = 3;
            day_week = (day_week + 1) % 7;
        }
        // Else if last day of Feb and not leap year
        else if (day_of_month == 28 && month == 2) {
            day_of_month = 1;
            month = 3;
            day_week = (day_week + 1) % 7;
        }
        // Else if last day of 30 day month
        else if (day_of_month == 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
            day_of_month = 1;
            month = month + 1;
            day_week = (day_week + 1) % 7;
        }
        // Else if last day of 31 day month
        else if (day_of_month == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)) {
            day_of_month = 1;
            month = month + 1;
            day_week = (day_week + 1) % 7;                
        }
        // Else go to next day
        else {
            day_of_month = day_of_month + 1;
            day_week = (day_week + 1) % 7;
        }
    }

    printf("Number of Sundays on first of month is: %i", sundays_count);
}
