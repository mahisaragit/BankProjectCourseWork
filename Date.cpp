//Date.cpp

#include "Date.h"
#include<iostream>
#include<stdexcept>
#include<vector>
#include<iomanip>

using namespace std;

ostream& operator<<(ostream& output, const Date& date) {
	output << date.month << "/" << date.day << "/" << date.year;
	return output;
}

Date::Date() {
	month = NULL;
	day = NULL;	
	year = NULL;
}
Date::Date(int m, int d, int y) {
	setDate(m, d, y);
}

void Date::setDate(int m, int d, int y) {
	setMonth(m);
	setDay(d);
	setYear(y);
}

void Date::setMonth(int m) {
	if (m <= 0 || m > 12) {
		throw invalid_argument("Month out of range, Month should range from 1-12\n");
	}
	else
		month = m;
}

void Date::setDay(int d) {
	if (d > 0 && d <= daysPerMonth[month - 1])
		day = d;

	else
		if (d == 29 && month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
			day = d;

		else
			throw invalid_argument("Invalid Month\n");
}

void Date::setYear(int y) {
	if ( y <1920)
		throw invalid_argument("Invalid Year\n");
	else
		year = y;
}

int Date::getMonth()const {
	return month;
}

int Date::getDay()const {
	return day;
}

int Date::getYear()const {
	return year;
}

void Date::printDate()const {
	cout <<setfill('0')<< setw(2) << getMonth() << "/" << setw(2) << getDay() << "/" <<setw(4)<< getYear();
}

